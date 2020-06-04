#include "funciones.h"

#include <iostream>
#include <sstream>
#include <fstream>

void participantes() {
    std::cout << std::endl << "=== Tarea 2 ===" << std::endl;
    std::cout << std::endl << "Edgar Matus" << std::endl;
    std::cout << std::endl << "Oscar Peñaloza" << std::endl;
    std::cout << std::endl << "Daniela Galleguillos" << std::endl;
}

std::vector<int> obtenerPuntajes(std::string linea) {
    std::vector<int> arreglo;
    std::stringstream ss(linea);
    std::string item;

    while (std::getline(ss, item, ';')) {
        int valor = atoi(item.c_str());
        arreglo.push_back(valor);
    }

    return arreglo;
}   

std::vector<int> obtenerPonderaciones(std::string linea) {
    std::vector<int> arreglo;
    std::stringstream ss(linea);
    std::string item;

    while (std::getline(ss, item, ',')) {
        int valor = atoi(item.c_str());
        arreglo.push_back(valor);
    }

    return arreglo;
}   

std::vector<std::string> calcularPonderacion(int nem, int ranking, int matematicas, int lenguaje, int ciencias, int historia){

}