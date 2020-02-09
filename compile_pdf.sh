#!/usr/bin/env bash

# Usage: ./compile_pdf.sh [problem-id]

contestName="2020臺南一中校內賽"

cd "$1"

echo "Compiling $1"

pandoc -M contestName="$contestName" -T "" problem.md -o problem.pdf --template ../template.tex -f markdown -t latex -s --pdf-engine=xelatex

echo "Compile Finish"