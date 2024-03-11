import re
import os
import json
import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib import font_manager as fm

font_path = './fonts/HelveticaNeue.ttf'  # Your font path goes here
fe = fm.FontEntry(
    fname=font_path,
    name='Helvetica Neue')
fm.fontManager.ttflist.insert(0, fe)
plt.rcParams['font.family'] = fe.name

color_pallete = ['#ef476f', '#ffd166', '#06d6a0', '#ff8fab', '#00b4d8', '#03045e']
texture_pallete = ['|', '\\', '+', 'x', 'o', 'O', '.', '*'] 
# the categories of we plot, order matters
categories = ["Allo", "ScaleHLS", "HeteroCL", "PyLog", "Dahlia", "VitisHLS"]

def normalize_throughput(data):
    new_data = {}
    for case in data:
        new_data[case] = {}
        # baseline is "VitisHLS"
        baseline_throughput = 1000 / data[case]["VitisHLS"]
        for cat in data[case]:
            throughput = 1000 / data[case][cat]
            new_data[case][cat] = throughput / baseline_throughput # speedup

    return new_data


def draw_plots(data, ylabel_fontsize=20, xticks_fontsize=20, yticks_fontsize=16, legend_fontsize=18):
    keys = list(data.keys())
    values = {cat: [data[key][cat] for key in keys] for cat in categories}

    # Create the plots
    fig, ax1 = plt.subplots()
    fig.set_size_inches(18, 4)
    plt.subplots_adjust(left=0.05, right=0.95, bottom=0.1, top=0.9)

    width = 0.15
    # Add horizontal reference lines
    ref_lines = [1, 10, 100, 500, 1000, 2000, 5000]
    for ref_line in ref_lines:
        ax1.axhline(y=ref_line, color='gray', alpha=0.2, linestyle='-', xmin=0, xmax=1)

    x = range(len(keys))
    for i, cat in enumerate(categories):
            bars = ax1.bar([pos+width/2 + width * i for pos in x], values[cat], width=width, label=cat, color=color_pallete[i])
            if i > 0: continue
            for bar in bars:
                height = bar.get_height()
                # round height to int
                height = int(height)
                plt.text(bar.get_x() + bar.get_width() / 2., 1.05 * height, f'{height}$\\times$', ha='center', va='bottom', fontsize=yticks_fontsize, color='red')

    

    ax1.set_yscale('log')
    yticks = ref_lines
    ax1.set_yticks(yticks)
    ax1.set_yticklabels(yticks, fontsize=yticks_fontsize)
    ax1.tick_params(axis='y', labelsize=yticks_fontsize)

    # Adjust the x-axis
    xticks = [i + len(categories) * width / 2 for i in range(len(keys))]
    ax1.set_xticks(xticks)
    ax1.set_xticklabels(keys, rotation=0, ha='center', fontsize=xticks_fontsize)  # Tilt the x-axis labels
    
    # Set the y-axis label
    ax1.set_ylabel('Speedup over Vitis HLS', fontsize=ylabel_fontsize)
    
    # Set the legend to spread horizontally on the top with 2 columns (you can adjust ncol as needed)
    legend = ax1.legend(loc='upper right', bbox_to_anchor=(0.9, 1), fontsize=legend_fontsize, ncol=6)

    # tight x limit
    ax1.set_xlim([- 2 * width, len(keys) + 0 * width])
    ax1.set_ylim([0.1, 11000])

    plt.tight_layout()

    # Save to file
    plt.savefig('polybench.png', dpi=300)
    # Print a message 
    print("Plot saved to file: polybench.png")



if __name__ == "__main__":
    # load dataset
    with open('dataset.json', 'r') as f:
        dataset = json.load(f)
    
    # normalize throughput
    dataset = normalize_throughput(dataset)

    # draw plots
    draw_plots(dataset)