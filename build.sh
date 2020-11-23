#!/usr/bin/env bash

gcc "shell.c" -o "shell"
for i in "./src"/*
do
    NAME="$(basename $i .c)"
    gcc "$i" -o "./objFiles/$NAME"
done