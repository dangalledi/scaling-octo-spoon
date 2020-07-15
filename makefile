CXX = g++
CXXFLAGS = -g3 -Wall -fopenmp
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

Carrera.o: directorios Carrera.cpp
	$(CXX) $(CXXFLAGS) -c Carrera.cpp -o build/Carrera.o

Estudiante.o: directorios Estudiante.cpp
	$(CXX) $(CXXFLAGS) -c Estudiante.cpp -o build/Estudiante.o

funciones.o: directorios funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp -o build/funciones.o

main.o: directorios main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o funciones.o Estudiante.o Carrera.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/funciones.o build/Carrera.o $(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build *.csv

.DEFAULT_GOAL := all