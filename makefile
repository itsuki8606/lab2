main: compute.o main.o
g++ -o compute main.o compute.o

compute.o: compute.cpp compute.h
g++ -c compute.cpp

main.o: main.cpp compute.h
g++ -c main.cpp
