CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall -fopenmp
MKDIR = mkdir -p

LIBS = -lm 

directorios:
	$(MKDIR) build dist

Estudiante.o: directorios Estudiante.cpp Estudiante.h
	$(CXX) $(CXXFLAGS) -c Estudiante.cpp -o build/Estudiante.o
	
funciones.o: directorios funciones.cpp funciones.h
	$(CXX) $(CXXFLAGS) -c funciones.cpp -o build/funciones.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o funciones.o Estudiante.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/funciones.o build/Estudiante.o $(LIBS) 
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build *.csv

.DEFAULT_GOAL := all
