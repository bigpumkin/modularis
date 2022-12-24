#!/usr/bin/env bash
# Requirements:
# pkg install x11-repo
# pkg install sfml
clang++ -o modularis main.cpp module/*.cpp -I./ -lsfml-system -lsfml-graphics -lsfml-window
