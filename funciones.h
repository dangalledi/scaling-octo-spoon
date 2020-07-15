#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>

#include "Carrera.h"

/**
 * Función que muestra los participantes del grupo
 */
void participantes();

/**
 * 
 * @param Línea leída desde un archivo
 * @return el arreglo con los datos
 */
std::vector<int> obtenerDatos(std::string linea);

/**
 * Crea un vector de carreras con los datos de un archivo admision.csv
 * @return Vector con carreras 
 */
std::vector<Carrera> VectorDeCarreras();

/**
 * Imprime en la salida estándar un vector
 * @param arreglo Vector a mostrar
 */
void imprimirVectordeCarreras(std::vector<Carrera> arreglo);

/**
 * Funcion que ordena carreras por cantidad de vacantes
 */
void quickSortVacantes(std::vector<Carrera>& arreglo, int inicio, int final);
int partitionVacantes(std::vector<Carrera>& arreglo, int inicio, int final);

/**
 * Funcion que ordena carreras por primer matriculado 
 */
void quickSortPrimer(std::vector<Carrera>& arreglo, int inicio, int final);
int partitionPrimer(std::vector<Carrera>& arreglo, int inicio, int final);

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
