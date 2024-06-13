#!/bin/bash

lang="$1"
ifile="$2"
ofile="$3"
execrule="$4"

if [ "$lang" = "help" ]
then
  echo "compile [file] [output] [execute]"
  echo "Allows a user to compile programs"
  echo ""
  echo "Command Usage: compile ¬"
  echo "  [Lang] - Language"
  echo "  [File] - Input file"
  echo "  [Output] - Output file (leave blank for output.o)"
  echo "  [Execute] - Execute after compilation, y or n (leave blank for n) (Alias: 'execute')"
  exit 0
fi

cpp() {
  if [ "$execrule" = "y" ]
  then
    clear
    g++ -std=c++17 -o "$ofile" "$ifile"
    ./"$ofile"
    exit
  else
    if [ -z "$ifile" ]
    then
      echo "Error: Command missing input file"
      exit
    elif [ -z "$ofile" ]
    then
      echo "Defaulting to output.o"
      g++ -std=c++17 -o "output.o" "$ifile"
      exit
    else
      g++ -std=c++17 -o "$ofile" "$ifile"
      exit
    fi
  fi
}

if [ "$lang" = "c++" ] || [ "$lang" = "cpp" ]
then
  cpp
elif [ -z "$lang" ]
then
  echo "No inputs found, use 'compile help' to view the help command"
else
  echo "Language Not Found (Did you spell it correctly?)"
  exit
fi
