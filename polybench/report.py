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
all_latency = []
all_dsp = []
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
        if framework != "scalehls":
            dsp_ratio = "N/A"
        else:
            dsp_ratio = f"1/{all_dsp[-5] / int(dsp):.1f}x"
        all_dsp.append(int(dsp))
        latency = int(avg_lat) * 1e-3
        if framework != "scalehls":
            speedup = "N/A"
        else:
            speedup = f"{latency / all_latency[-5]:.1f}x"
        all_latency.append(latency)
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
        if framework == "scalehls":
            loc = "N/A"
        else:
            with open(f"{framework}/{benchmark}/{benchmark}.cpp", "r") as cppfile:
                loc = 0
                for line in cppfile:
                    if line.startswith("//"):
                        continue
                    if line.strip() == "":
                        continue
                    loc += 1
        results.append(
            (framework, benchmark, f"{latency:.1f}K ({speedup})", ii, f"{dsp} ({dsp_ratio})", f"{freq:.0f}", loc)
        )

headers = ["Framework", "Benchmark", "Latency (ms)", "II", "DSP", "PnR Freq. (MHz)", "Opt. HLS"]
table = tabulate(results, headers=headers)
print(table)
