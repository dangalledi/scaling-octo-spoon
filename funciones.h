#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <random>
#include <vector>
#include <string.h>

/**
 * Función que muestra los participantes del grupo
 */
void participantes();

/**
 * 
 * @param linea linea del archivo
 * @return vector con puntajes
 */
std::vector<int> obtenerPuntajes(std::string linea);

/**
 * 
 * @param linea
 * @return 
 */
std::vector<int> obtenerPonderaciones(std::string linea);

/**
 * 
 * @param nem
 * @param ranking
 * @param matematicas
 * @param lenguaje
 * @param ciencias
 * @param historia
 * @return 
 */
std::vector<std::string> calcularPonderacion(int nem, int ranking, int matematicas, int lenguaje, int ciencias, int historia);

#endif /* FUNCIONES_H */
