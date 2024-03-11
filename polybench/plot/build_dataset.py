import os
import json

# read "dataset_paper.json"
with open('dataset_paper.json', 'r') as f:
    dataset = json.load(f)


tools = {
    "Allo" : "allo",
    "ScaleHLS" : "scalehls",
    "HeteroCL" : "heterocl",
    "Dahlia" : "dahlia",
    "PyLog" : "pylog",
    "VitisHLS": "vitis"
}

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

for toolname, directory in tools.items():
    # read in the results
    results_filename = f"../{directory}/results.json"
    if not os.path.exists(results_filename):
        print("WARNING: results file not found for", toolname)
        print("Skipping", toolname)
        continue
    with open(results_filename, 'r') as f:
        results = json.load(f)

    # update dataset 
    for benchmark in benchmarks:
        dataset[benchmark][toolname] = results[benchmark]

# save dataset to file
with open('dataset.json', 'w') as f:
    json.dump(dataset, f, indent=4)