import os
import xml.dom.minidom as minidom
from tabulate import tabulate
import json

assert os.system("which vitis_hls >> /dev/null") == 0, "Vitis HLS not found in PATH"
benchmarks = [
    "2mm",
    "3mm",
    "atax",
    "bicg",
    "correlation",
    "gemm",
    "gesummv",
    "jacobi_2d",
    "mvt",
    "symm",
    "syr2k",
    "syrk",
    "trmm",
]
results = []
for i, benchmark in enumerate(benchmarks):
    print(f"[{i+1}/{len(benchmarks)}] Start running {benchmark}...")
    os.system(f"cd {benchmark} && vitis_hls -f run.tcl")
    report = minidom.parse(
        open(f"{benchmark}/{benchmark}.prj/solution1/syn/report/kernel_{benchmark}_csynth.xml", "r")
    )
    clock = (
        report.getElementsByTagName("UserAssignments")[0]
        .getElementsByTagName("TargetClockPeriod")[0]
        .childNodes[0]
        .data
    )
    avg_lat = (
        report.getElementsByTagName("PerformanceEstimates")[0]
        .getElementsByTagName("SummaryOfOverallLatency")[0]
        .getElementsByTagName("Worst-caseLatency")[0]
        .childNodes[0]
        .data
    )
    latency = float(clock) * int(avg_lat) * 1e-6
    results.append((benchmark, latency))
    print(f"{benchmark}: {latency:.4f}ms\n")

headers = ["Benchmark (Allo)", "Latency (ms)"]
table = tabulate(results, headers=headers)
print(table)


# convert results to dict
results = dict(results)
# replace key "jacobi_2d" with "jacobi-2d"
results["jacobi-2d"] = results.pop("jacobi_2d")
# save results to file
with open('results.json', 'w') as f:
    json.dump(results, f, indent=4)