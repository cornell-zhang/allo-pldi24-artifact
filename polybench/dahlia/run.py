import os
import json
from tabulate import tabulate

assert os.system("which vitis_hls >> /dev/null") == 0, "Vitis HLS not found in PATH"
benchmarks = [
    "2mm",
    "3mm",
    "atax",
    "bicg",
    "correlation",
    "gemm",
    "gesummv",
    "jacobi-2d",
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
    report = json.load(
        open(f"{benchmark}/output.prj/solution1/solution1_data.json", "r")
    )
    latency = (
        float(report["ClockInfo"]["ClockPeriod"])
        * int(report["ClockInfo"]["Latency"])
        * 1e-6
    )
    results.append((benchmark, latency))
    print(f"{benchmark}: {latency:.4f}ms\n")

headers = ["Benchmark (Dahlia)", "Latency (ms)"]
table = tabulate(results, headers=headers)
print(table)
