#!/bin/sh

g++ -o main main.cpp CPU.cpp GUI.cpp `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

./main *.gb