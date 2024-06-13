#!/bin/bash

echo "alias compiler=\"./compiler/compiler.sh\"">>$HOME/.bashrc
echo "alias compile=\"./compiler/compile/compile.sh\"">>$HOME/.bashrc
echo "alias execute=\"./compiler/compile/execute.sh\"">>$HOME/.bashrc

sudo chmod u+x compiler/compiler.sh
sudo chmod u+x compiler/compile/compile.sh
sudo chmod u+x compiler/compile/execute.sh
sudo chmod u+x compiler/compile/interpret.sh
