#include <iostream>
#include <fstream>
#include "omp.h"
#include <chrono>
#include "funciones.h"


using namespace std;


/**
 * Taller 2
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return salida del programa
 */
int main(int argc, char** argv) {

    //tiempo de ejecucion
    auto inicio = std::chrono::system_clock::now();

    if(argc > 1){

        //ponderaciones
        int opcion;

        try{
            opcion = std::atoi(argv[1]);
        }
        catch(std::invalid_argument const &e){ 
            cout << "No se llama" << argv[1] << endl;
        }

        if(opcion == 1){
            //generar los archivos de las carreras 

            string rutaPuntajes = argv[2];
            std::ifstream entrada(rutaPuntajes);

            if(entrada){    
#pragma omp parallel
            {
#pragma omp single
                {
                    for (std::string linea; getline(entrada, linea);) {
#pragma omp task
                        {
                            string rutaSalida = argv[3];
                            std::vector<int> puntajes = obtenerPuntajes(linea);
                            if(puntajes.size() >= 6) {
                                
                                int rut = puntajes.at(0);
                                int nem = puntajes.at(1);
                                int ranking = puntajes.at(2);
                                int matematica = puntajes.at(3);
                                int lenguaje = puntajes.at(4);
                                int ciencias = puntajes.at(5);
                                int historia = puntajes.at(6);

                                //calculo de porcentajes para cada carrera  
                                //###################################
                                //escribir el resultado
#pragma omp critical                                
                                salida << rut << ", " << fila.at(1) << std::endl;
                                salida.close();
                            }
                        }                       
                    }
                }
            }
            }else{
                cout << "fallo el archivo" << endl;
            }

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

    auto termino = std::chrono::system_clock::now();
    auto duracion = chrono::duration_cast<chrono::nanoseconds>(termino - inicio).count();

    return EXIT_SUCCESS;
}

