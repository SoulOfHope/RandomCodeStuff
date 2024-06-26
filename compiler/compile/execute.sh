#!/bin/bash

if [ "$1" = "help" ]
then
  echo "execute [file]"
  echo "A subcommand of compile, compiles then executes, before removing the compiled file"
  echo ""
  echo "Command Usage: execute ¬"
  echo "  [Lang] - Language to execute in"
  echo "  [File] - Input file"
  exit 0
fi

if [ "$1" = "c++" ] || [ "$1" = "cpp" ]
then
  clear && g++ -std=c++17 -o "temp.o" "$2" && ./"temp.o" && sleep .5 && rm -rf "temp.o"
elif [ "$1" = "python" ] || [ "$1" = "py" ]
then
  clear && python -V && python "$2"
else
  echo "Language not found, Did you spell it correctly?"
fi