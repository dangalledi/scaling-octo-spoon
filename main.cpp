#include <iostream>
#include <fstream>
#include <vector>
#include "omp.h"
#include <chrono>
#include "funciones.h"
#include "Estudiante.h"
#include "Carrera.h"

using namespace std;

/**
 * Taller 2
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {
    
    int opcion;
    
    try{
        int opcion = std::atoi(argv[1]);

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;

    } catch (...) {
        std::cerr << "Error no manejado" << std::endl;
    } 

    if(argc > 1){

        //abrir archivo de ponderaciones necesarias
        
        //control de tiempo de ejecucion, tiempo de inicio
        auto start = std::chrono::system_clock::now();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float,std::milli> duration = end - start;

        std::vector<Estudiante> arreglo;
        std::vector<Carrera> TodasLasPinchesCarreras;

        if(opcion == 1){
            //generar archivos

            string rutaPuntajes = argv[2];
            std::ifstream entrada(rutaPuntajes);
            
            TodasLasPinchesCarreras= VectorDeCarreras();                  // Se guardan todas las carreras en vector<Carrera>
            quickSortVacantes(TodasLasPinchesCarreras,0,TodasLasPinchesCarreras.size());            // Se ordena por vacantes las carreras 
            quickSortPrimer(TodasLasPinchesCarreras,0,TodasLasPinchesCarreras.size());              // Se ordena por primer matriculado las carreras 

            if(entrada){    
#pragma omp parallel
            {
#pragma omp single
                {
                    for (std::string linea; getline(entrada, linea);) {
#pragma omp task
                        {
                            string rutaSalida = argv[3];
                            
                            std::vector<int> puntajes = obtenerDatos(linea);
                            if(puntajes.size() >= 6) {

                                Estudiante postulante(linea);  // Se tiene un postulante 

                                //calculo de porcentajes para cada carrera
                                std::vector<string> fila;  
                                fila = calcularPonderacion(nem, ranking, matematica, lenguaje, ciencias, historia);
                                rutaSalida = rutaSalida + fila[0] + ".txt";
                                std::ofstream salida(rutaSalida, fstream::app);
                                //cout << "inscrito el rut: " << rut << " en la carrera: " << fila.at(0) << endl;
                                //escribir el resultado
#pragma omp critical                                
                                salida << rut << ", " << fila.at(1) << std::endl;
                                salida.close();
                            }
                            puntajes.clear();
                        }                       
                    }
                }
            }
            }else{
                cout << "fallo al encontrar el archivo" << endl;
            }
            std::cout << duration.count() << "s" << std::endl;

        }
        else if(opcion == 2){
            //busqueda de rut

            int rut;
            string ruta = argv[3];
            std::ifstream archivos(ruta);
            try{
                rut = std::atoi(argv[2]);
            }catch(std::invalid_argument const &e){
                cout << "rut invalido " << argv[2] << endl;
            }

            if(archivos){
                //codigo
            }else{
                participantes();
            }
        }
        else{
            participantes();
        }

    }else{
        participantes();
    }
    return EXIT_SUCCESS;
}

