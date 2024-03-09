# Allo Artifact

**Need DOI here**

This repository contains scripts for setting up environments and reproducing results presented in the PLDI 2024 paper entitled [Allo: A Programming Model for Composable Accelerator Design](). If you wish to access the core implementation, documentation, and tutorials for the Allo language, please refer to the following links. We encourage you to explore these resources if you are interested in using Allo for designing other hardware accelerators that are not presented in our paper.

* Allo repository: <https://github.com/cornell-zhang/allo>
* Allo documentation: <https://cornell-zhang.github.io/allo>

## Clone the Repository

Please clone the repository with the `--recursive` flag to include the submodules.

```bash
git clone https://github.com/cornell-zhang/allo-pldi24-artifact.git --recursive
cd allo-pldi24-artifact
```

## Setup Docker Image

We have already built the docker on our server, so the AE reviewers do *not* need to pull or build the docker image again.

### Pull from Docker Hub

We provide a pre-built docker image available on Docker Hub which is compatible with NVIDIA V100 GPUs with CUDA 11.7 installed, user can pull it with:
```bash
docker image pull allo-org/allo-ae:latest
docker tag allo-org/allo-ae:latest allo
```

### Build from source

Otherwise, users can run the following command to build the docker container. It will take about **2 hours** to build the docker image. The docker image contains the necessary environment, libraries, source code, and datasets for reproducing the results.
```bash
cd 3rdparty/allo/docker
docker build -t allo -f docker/Dockerfile .
```

## Kick-the-Tires (Est. Time: 10 mins)

We will run some basic tests on the artifact to make sure the environment is set up correctly. User can use the following command to run the unit tests:
```bash
docker run -it allo /bin/bash -c '...'
```

You are expected to see the following output.

```
...
```

## Run Experiments (Est. Time: X hours)

Below is the script to reproduce experiments in Allo paper. Each script will emit logging files and figures in pdf format.

We only provide scripts for reproducing the results of **Figure 7**, **Table 4**, and **Figure 9**, which construct the main conclusion of our paper. For other experiments, since they may require multiple machines or take excessively long time to run, we do not provide end-to-end evaluation scripts, but users can still find the instructions in our repository.


### Figure 10 - PolyBench (Est. Time: X hours)
| Benchmark | Script |
| --- | --- |
| [2mm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/2mm/2mm.c#L75-L105) |
| [3mm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/3mm/3mm.c#L71-L110) |
| [atax](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/atax/atax.c#L64-L86) |
| [bicg](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/bicg/bicg.c#L72-L96) |
| [correlation](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/datamining/correlation/correlation.c#L65-L124) |
| [gemm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/gemm/gemm.c#L72-L99) |
| [gesummv](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/gesummv/gesummv.c#L68-L96) |
| [jacobi-2d](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/stencils/jacobi-2d/jacobi-2d.c#L64-L84) |
| [mvt](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/kernels/mvt/mvt.c#L77-L96) | 
| [symm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/symm/symm.c#L73-L105) |
| [syr2k](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/syr2k/syr2k.c#L72-L99) |
| [syrk](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/syrk/syrk.c#L67-L93) |
| [trmm](https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1/blob/3e872547cef7e5c9909422ef1e6af03cf4e56072/linear-algebra/blas/trmm/trmm.c#L69-L94) |

## Further Customization


### Tutorials
We also provide detailed documentation and tutorials for users who are interested in using Allo for designing different hardware accelerators. Please refer to this [webpage](https://cornell-zhang.github.io/allo) for more information.


## More information
For AE reviewers, please contact the authors through [HotCRP](https://pldi24ae.hotcrp.com/) for any questions. For other users, please open an [issue](https://github.com/cornell-zhang/allo-pldi24-artifact/issues) publicly or contact [chhzh123](mailto:hzchen@cs.cornell.edu) for any technical questions.
