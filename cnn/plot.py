import xml.dom.minidom as minidom
from tabulate import tabulate

benchmarks = ["vgg16", "mobilenet", "resnet18"]
frameworks = ["allo", "scalehls"]
results = {"allo": [], "scalehls": []}


def get_results(benchmark, framework):
    report = minidom.parse(
        open(
            f"{benchmark}/{benchmark}_{framework}.prj/solution1/syn/report/main_graph_csynth.xml",
            "r",
        )
    )
    worst_lat = (
        report.getElementsByTagName("PerformanceEstimates")[0]
        .getElementsByTagName("SummaryOfOverallLatency")[0]
        .getElementsByTagName("Worst-caseLatency")[0]
        .childNodes[0]
        .data
    )
    ff = (
        report.getElementsByTagName("AreaEstimates")[0]
        .getElementsByTagName("Resources")[0]
        .getElementsByTagName("FF")[0]
        .childNodes[0]
        .data
    )
    lut = (
        report.getElementsByTagName("AreaEstimates")[0]
        .getElementsByTagName("Resources")[0]
        .getElementsByTagName("LUT")[0]
        .childNodes[0]
        .data
    )
    bram = (
        report.getElementsByTagName("AreaEstimates")[0]
        .getElementsByTagName("Resources")[0]
        .getElementsByTagName("BRAM_18K")[0]
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
    return (
        benchmark,
        framework,
        f"{(float(worst_lat) * 1e-6):.2f}M",
        f"{float(ff) * 1e-3:.0f}K",
        f"{float(lut) * 1e-3:.0f}K",
        bram,
        dsp,
    )


for benchmark in benchmarks:
    for framework in frameworks:
        results[framework].append(get_results(benchmark, framework))

headers = ["Benchmark", "Framework", "Latency (cycles)", "FF", "LUT", "BRAM", "DSP"]
table = tabulate(results["allo"] + results["scalehls"], headers=headers)
print(table)

print("Speedup:")
print(
    "vgg16:", float(results["scalehls"][0][2][:-1]) / float(results["allo"][0][2][:-1])
)
print(
    "mobilenet:",
    float(results["scalehls"][1][2][:-1]) / float(results["allo"][1][2][:-1]),
)
print(
    "resnet18:",
    float(results["scalehls"][2][2][:-1]) / float(results["allo"][2][2][:-1]),
)
