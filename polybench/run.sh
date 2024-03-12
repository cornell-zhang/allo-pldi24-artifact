#!/bin/bash

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
