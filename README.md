# Allo Artifact

**Need DOI here**

This repository contains scripts for setting up environments and reproducing results presented in the PLDI 2024 paper entitled [Allo: A Programming Model for Composable Accelerator Design](). If you wish to access the core implementation, documentation, and tutorials for the Allo language, please refer to the following links. We encourage you to explore these resources if you are interested in using Allo for designing other hardware accelerators that are not presented in our paper.

* Allo repository: <https://github.com/cornell-zhang/allo>
* Allo documentation: <https://cornell-zhang.github.io/allo>

## Clone the Repository

Please clone the repository following the instruction below. You can include the `--recursive` flag to download all the baseline systems under the `3rdparty` directory. Notice this may take a while to download all the baseline systems since most of the baselines require a separate LLVM build. **For AE, you can directly leverage the provided [docker image](https://hub.docker.com/repository/docker/alloprj/allo-container/general), which has already set up the required environment.**

```bash
git clone https://github.com/cornell-zhang/allo-pldi24-artifact.git
cd allo-pldi24-artifact
```

## Setup Environment (Est. Time: 30 mins)

We have already built a docker image that contains necessary packages, including the Allo library and the baseline systems. Since our experiments involve invoking the AMD Vitis toolchain for FPGA synthesis, we provide a separate Vitis image for artifact evaluation. Below are the instructions for setting up the environment.

### Allo and Baseline Systems

#### Pull Docker Image from Docker Hub

We provide a pre-built docker image available on Docker Hub. User can pull it with:
```bash
docker image pull alloprj/allo-container:latest
docker tag alloprj/allo-container:latest allo
```

#### Build from source

If you do not want to use the pre-built docker, we also provide detailed instructions on how to build the baseline systems from scratch. Please refer to this [link](3rdparty/README.md) for more information.

### Vitis Toolchain

#### Image Copy (For AE Only)

```diff
- TODO: @Niansong
```

We provide an image that contains the necessary Vitis toolchain and can be downloaded from this [Drive](). Notice this is only for artifact evaluation and should *not* be used for other purpose. This link will be invalid after the artifact evaluation period.

The image is about 50GB and can be unzip using the following command:
```bash
tar -xzvf vitis-docker-volume.tar.gz
```

If you need full access to the Vitis toolchain, please download it from the official website following the instruction below.

#### Download from Official Website

To fully utilize the Vitis toolchain, please download from the [official website](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis/2022-1.html). We recommend using the Vitis 2022.1 version, which is the version we used for our experiments. Notice that you need to register an AMD account to download the toolchain.

Please visit the "[Vitis Core Development Kit - 2022.1 Full Product Installation](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis/2022-1.html)" webpage and download the "[Xilinx Unified Installer 2022.1: Linux Self Extracting Web Installer (BIN - 266.73 MB)](https://www.xilinx.com/member/forms/download/xef.html?filename=Xilinx_Unified_2022.1_0420_0327_Lin64.bin)". You can follow the [official instruction](https://docs.xilinx.com/r/2022.1-English/ug1400-vitis-embedded/Installing-the-Vitis-Software-Platform) install the Vitis toolchain.


## Kick-the-Tires (Est. Time: 10 mins)

To make sure the environment runs smoothly, we first examine if the docker and the required packages are installed correctly. You can launch the docker image with the following command. Notice that you need to replace `/your/path/to/vitis-docker-volume/` with the path to the Vitis toolchain that you downloaded from the official website or the path to the unzipped image.
```bash
docker run -v /your/path/to/vitis-docker-volume/:/tools/xilinx -it allo-container:latest /bin/bash
```

### Check Vitis Toolchain

Inside the docker image, you can check if the Vitis toolchain is installed correctly by running the following command. The output should be the path to the `vitis_hls` binary.
```
(py312) root@00ad1aec9529:~/allo# which vitis_hls
/tools/xilinx/Vitis_HLS/2022.1/bin/vitis_hls
```

### Run Unit Tests

We will run some basic tests on the artifact to make sure the environment is set up correctly. Inside the docker image, you can use the following command to run the unit tests:
```bash
cd /root/allo && python3 -m pytest tests
```

You are expected to see the following outputs:
```
================================== 197 passed, 1 skipped, 62 warnings in 86.76s (0:01:26) ===================================
```

Congratulations! You have successfully set up the environment and passed the basic tests :) You can now proceed to the next step to reproduce the experiments in the paper.


## Reproduce Experiments (Est. Time: 17 hours)

Below are the scripts to reproduce experiments in Allo paper. Each script will emit logging files that are used to generate the final results.

We provide scripts for reproducing the results of **Figure 10**, **Table 3**, and **Table 4**, which construct the main conclusion of our paper. For Figure 12, it requires a U280 FPGA to run the experiment. Due to campus security settings, we are unable to grant reviewers access to the machine, and thus, Figure 12 is not part of the artifact evaluation. However, we provide the code and instructions for users with access to FPGA machines. Additionally, the synthesis report is included for reference.

First, we can run the following command to enter the docker image. It will mount the Vitis toolchain and the AE folder to the docker, so please make sure you have already cloned this repository and downloaded the Vitis toolchain. We highly recommend **lanuching a `tmux` terminal before executing the docker image**, as the experiments may take a long time to finish. 

```bash
docker run -v /your/path/to/vitis-docker-volume/:/tools/xilinx -v $(pwd):/root/allo-pldi24-artifact -it allo-container:latest /bin/bash
```

### Figure 10 - PolyBench (Est. Time: 20 hours)
As it requires more than 200G disk space to install all the baseline packages, we do not contain all the packages in the docker image, and thus will not perform end-to-end code generation, which also costs lots of time. Instead, we generate the optimized HLS C++ code from each baseline offline, and reviewers only need to run the Vitis HLS to obtain the final report. Specifically, the HLS C++ code from [ScaleHLS](https://github.com/hanchenye/scalehls), [HeteroCL](https://github.com/cornell-zhang/heterocl), [Pylog](https://github.com/hst10/pylog), and [Dahlia](https://github.com/cucapra/dahlia) are generated offline.

For end-to-end testing (not for AE), we also include the scripts to generate the optimized HLS C++ code from each baseline. Please refer to this [link](3rdparty/README.md) to install the required packages and generate the optimized HLS C++ code.

#### Experimental Settings

We evaluate the following benchmarks from [PolyBench](https://web.cs.ucla.edu/~pouchet/software/polybench/). The reference implementation is available in the [PolyBenchC-4.2.1](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1):
* [2mm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/2mm/2mm.c#L75-L105)
* [3mm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/3mm/3mm.c#L71-L110)
* [atax](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/atax/atax.c#L64-L86)
* [bicg](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/bicg/bicg.c#L72-L96)
* [correlation](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/datamining/correlation/correlation.c#L65-L124)
* [gemm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/gemm/gemm.c#L72-L99)
* [gesummv](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/gesummv/gesummv.c#L68-L96)
* [jacobi-2d](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/stencils/jacobi-2d/jacobi-2d.c#L64-L84)
* [mvt](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/mvt/mvt.c#L77-L96)
* [symm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/symm/symm.c#L73-L105)
* [syr2k](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/syr2k/syr2k.c#L72-L99)
* [syrk](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/syrk/syrk.c#L67-L93)
* [trmm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/trmm/trmm.c#L69-L94)

Each folder contains the original baseline implementation files and the generated HLS C++ files. You can go to each folder to check the details. For example, `polybench/allo/2mm` is the Allo implementation for the 2mm benchmark, and there are three files under this folder:
* `two_mm.py`: The Allo implementation
* `two_mm.cpp`: The generated HLS C++ file
* `run.tcl`: The Vitis HLS script to run the synthesis

#### Run the Experiment
Inside the docker, you can use the following command to run the experiment:

```bash
cd /root/allo-pldi24-artifact/polybench
# Allo (Est. Time: 6 hours)
cd allo && python3 run.py
# ScaleHLS (Est. Time: 4 hours)
cd ../scalehls && python3 run.py
# HeteroCL (Est. Time: 3 hours)
cd ../heterocl && python3 run.py
# Pylog (Est. Time: 1 hour)
cd ../pylog && python3 run.py
# Dahlia (Est. Time: 1 hour)
cd ../dahlia && python3 run.py
# Vitis (Est. Time: 1 hour)
cd ../vitis && python3 run.py
```

If you want to speed up the above experiments, you can invoke multiple terminals/processes to run the experiments in parallel. Since Vitis HLS only leverages one CPU core to run the synthesis, experiments of different frameworks can be run in parallel without impacting the final results.

The results will be dumped to each folder. Lastly, we can call the following command to collect the results and generate the final figure.

```diff
- TODO: @Niansong
```

### Table 3 (Est. Time: 1 min)
Please conduct the experiments in Figure 10 first.

```diff
- TODO: @Niansong
```

### Table 4 - CNN (Est. Time: 3 hours)
Next, we run the experiments for multiple kernels. We leverage the three CNN models, including [MobileNet](https://arxiv.org/abs/1704.04861), [ResNet18](https://arxiv.org/abs/1512.03385), and [VGG16](https://arxiv.org/abs/1409.1556), to evaluate the performance of Allo. The scripts to run the experiments are provided below.

Please run the following commands in the docker and make sure you have launched the `tmux` terminal in case the experiments take a long time to finish.
```bash
cd /root/allo-pldi24-artifact/cnn
# MobileNet
cd mobilenet
vitis_hls -f mobilenet_allo.tcl
vitis_hls -f mobilenet_scalehls.tcl
# ResNet18
cd ../resnet18
vitis_hls -f resnet18_allo.tcl
vitis_hls -f resnet18_scalehls.tcl
# VGG16
cd ../vgg16
vitis_hls -f vgg16_allo.tcl
vitis_hls -f vgg16_scalehls.tcl
```

After running all the neural network models, we can generate the result table by running:
```bash
cd /root/allo-pldi24-artifact/cnn
python3 plot.py
```

### Figure 12 - LLM (Not for AE)
As this experiment requires a U280 FPGA for evaluation, and needs ~24 hours to push the design from high-level synthesis to backend synthesis and generate bitstream, this experiment is **NOT for AE** purpose. However, we provide a [reference HLS C++ code](llm/), which is generated from Allo and later made some modifications to fit on the chiplet-based FPGA. Need to have device license and set up the `XDEVICE` to continue.

For the Allo frontend code, please refer to the [example](https://github.com/cornell-zhang/allo/tree/main/examples) folder in the Allo repository, which describes how to import models from [PyTorch](https://pytorch.org/) and generate the corresponding Allo code.


## Further Usage
### Examples
We provide a comprehensive sets of examples under the Allo repository.

### Tutorials
We also provide detailed documentation and tutorials for users who are interested in using Allo for designing different hardware accelerators. Please refer to this [webpage](https://cornell-zhang.github.io/allo) for more information.


## More information
For AE reviewers, please contact the authors through [HotCRP](https://pldi24ae.hotcrp.com/) for any questions. For other users, please open an [issue](https://github.com/cornell-zhang/allo-pldi24-artifact/issues) publicly or contact [chhzh123](mailto:hzchen@cs.cornell.edu) for any technical questions.
