import os
import re
import xml.dom.minidom as minidom
from tabulate import tabulate

frameworks = ["allo", "scalehls"]
benchmarks = [
    "atax",
    "correlation",
    "jacobi_2d",
    "symm",
    "trmm",
]
results = []
for framework in frameworks:
    for i, benchmark in enumerate(benchmarks):
        if framework == "scalehls":
            path = f"{framework}/{benchmark}/paper_result/{benchmark}.prj/solution1/syn/report/"
            name = f"{path}/test_{benchmark}_csynth.xml"
        else:
            path = f"{framework}/{benchmark}/{benchmark}.prj/solution1/syn/report"
            name = f"{path}/kernel_{benchmark}_csynth.xml"
        report = minidom.parse(open(name, "r"))
        clock = (
            report.getElementsByTagName("UserAssignments")[0]
            .getElementsByTagName("TargetClockPeriod")[0]
            .childNodes[0]
            .data
        )
        overall_lat = report.getElementsByTagName("PerformanceEstimates")[
            0
        ].getElementsByTagName("SummaryOfOverallLatency")[0]
        if (
            len(overall_lat.getElementsByTagName("Average-caseLatency")) > 0
            and overall_lat.getElementsByTagName("Average-caseLatency")[0]
            .childNodes[0]
            .data
            != "undef"
        ):
            avg_lat = (
                overall_lat.getElementsByTagName("Average-caseLatency")[0]
                .childNodes[0]
                .data
            )
        else:
            avg_lat = (
                overall_lat.getElementsByTagName("Worst-caseLatency")[0]
                .childNodes[0]
                .data
            )
        dsp = (
            report.getElementsByTagName("AreaEstimates")[0]
            .getElementsByTagName("Resources")[0]
            .getElementsByTagName("DSP")[0]
            .childNodes[0]
            .data
        )
        latency = int(avg_lat) * 1e-3
        logfilename = f"{framework}/pnr/{benchmark}/vitis_hls.log"
        if not os.path.exists(logfilename):
            print(f"Error: {logfilename} does not exist")
            continue
        with open(logfilename, "r") as logfile:
            lines = logfile.readlines()
            for line in lines:
                if not line.startswith("CP achieved post-implementation:"):
                    continue
                p_lat = float(line.split(":")[1].strip())
                freq = 1000.0 / p_lat
                break
        rpt = open(f"{path}/csynth.rpt", "r").read()
        ii = max(list(map(int, re.findall(r"II=([0-9]*)", rpt))))
        results.append(
            (framework, benchmark, f"{latency:.1f}K", ii, dsp, f"{freq:.0f}")
        )

headers = ["Framework", "Benchmark", "Latency (ms)", "II", "DSP", "PnR Freq. (MHz)"]
table = tabulate(results, headers=headers)
print(table)
