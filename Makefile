# Makefile for Student Management System

CXX = g++
CXXFLAGS = -std=c++17 -I./include
SRC = main.cpp src/Student.cpp src/Course.cpp src/Enrollment.cpp src/SystemManager.cpp
TARGET = bin/main.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
