import os
from tabulate import tabulate

benchmarks = [
    "atax",
    "correlation",
    "jacobi-2d",
    "symm",
    "trmm"
]


results = []

for benchmark in benchmarks:
    logfilename = os.path.join(benchmark, "vitis_hls.log")
    if not os.path.exists(logfilename):
        print(f"Error: {logfilename} does not exist")
        continue
    with open(logfilename, "r") as logfile:
        lines = logfile.readlines()
        for line in lines:
            if not line.startswith("CP achieved post-implementation:"):
                continue
            latency = float(line.split(":")[1].strip())
            results.append((benchmark, 1000.0/latency))
            break

headers = ["PnR Frequency (Allo)", "MHz"]
table = tabulate(results, headers=headers)
print(table)