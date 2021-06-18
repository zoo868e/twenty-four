CC=g++
CXXFLAGS=-std=c++17 -g
dep:
	gcc -lstdc++ -M *.cpp > dep

-include dep 

all: main

main:main.o
clean:
	-find . -type f -name "*.o" -exec rm {} \;
	-find . -type f -name "dep" -exec rm {} \;
	-find . -type f -executable -name "*" -exec rm {} \;
