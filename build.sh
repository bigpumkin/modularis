#!/usr/bin/env bash
g++ -o modularis main.cpp module/*.cpp -I./ -lsfml-system -lsfml-graphics -lsfml-window
