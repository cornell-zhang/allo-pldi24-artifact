# Environment Setup for Allo and Other Baseline Systems

Please follow the guide below if you want to build the frameworks from scratch.
Firstly, make sure you have pulled the submodules with specific versions by running the following command.

```bash
git submodule update --init --recursive
```

## Allo
Please follow the guide in the [Allo](https://github.com/cornell-zhang/allo/tree/main/examples) repository. Here we only provide the easiest way to install all the dependencies of the Allo framework. It will automatically install LLVM18 and the MLIR dialect, which may take 100G+ disk space and 1-2 hours to build.

```bash
cd allo
conda create -n allo python=3.12
conda activate allo
bash build.sh
```

## ScaleHLS
Please follow the guide in the [ScaleHLS](https://github.com/hanchenye/scalehls) repository. We copy the installation script here for reference, but notice it will again install another version of LLVM and MLIR, which may takes lots of disk space and time.

```bash
cd scalehls
bash build-scalehls.sh
export PATH=$PATH:$PWD/build/bin:$PWD/polygeist/build/bin
export PYTHONPATH=$PYTHONPATH:$PWD/build/tools/scalehls/python_packages/scalehls_core
```

## HeteroCL
Please follow the [HeteroCL installation guide](https://cornell-zhang.github.io/heterocl/setup/index.html). HeteroCL uses LLVM15 for its backend, and the following script will automatically download and install the required packages.

```bash
cd heterocl
git submodule update --init --recursive
pip install .
export LLVM_BUILD_DIR=$(pwd)/hcl-dialect/externals/llvm-project/build
export PATH=${LLVM_BUILD_DIR}/bin:${PATH}
```

## Pylog
[Pylog](https://github.com/hst10/pylog) is a pure Python package, which can be directly downloaded and installed by the following command.

```bash
cd pylog
export PYTHONPATH=$(pwd):$PYTHONPATH
```

## Dahlia
Dahlia is a Scala-based DSL for hardware design, which requires to install the Java runtime. Please refer to the official [repository](https://github.com/cucapra/dahlia) for the installation guide. However, the Dahlia team has deployed a web-based interface for users to run the DSL without installing the environment. Therefore, we highly recommend users to leverage the [web interface](https://capra.cs.cornell.edu/dahlia/) for running Dahlia.
