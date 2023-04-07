cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp World.cpp Organism.cpp Organism.h Settings.h Animals/Animal.cpp Animals/Animal.h Animals/Czlowiek.cpp Animals/Czlowiek.h Animals/Antylopa.cpp Animals/Antylopa.h Plants/Trawa.cpp Plants/Trawa.h Plants/Plant.cpp Plants/Plant.h Plants/Mlecz.cpp Plants/Mlecz.h)
