#include "funciones.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

void participantes() {
    std::cout << std::endl << "=== Tarea 2 ===" << std::endl;
    std::cout << std::endl << "Daniela Galleguillos" << std::endl;
}

std::vector<int> obtenerDatos(std::string linea) {
    std::vector<int> arreglo;
    std::stringstream ss(linea);
    std::string item;

    while (std::getline(ss, item, ',')) {
        int valor = atoi(item.c_str());
        arreglo.push_back(valor);
    }

    return arreglo;
}  

std::vector<Carrera> VectorDeCarreras(){
    std::ifstream admision;
    admision.open("data/admision.csv", std::ios::in); 
    std::vector<Carrera> vector_datos;
    std::string aux = "noVacio";
    
    if(admision)
    {
        for (std::string texto;; getline(admision,texto))
        {
          if (aux != texto )
          {
            Carrera dato(texto);
            vector_datos.push_back(dato);
            aux = texto ;
          }else{
              for (long unsigned int i = 0; i < vector_datos.size(); i++){
                  if (vector_datos[i].GetCodigo()< 20000){
                      vector_datos.erase(vector_datos.begin() + i);
                  }
              }
              return vector_datos;
          }
        }
        return vector_datos;
    }else{
      std::cout << "no se hizo ni una wea en datos_admision" << std::endl;
    }
}

void imprimirVectordeCarreras(std::vector<Carrera> arreglo){
    std::cout << std::endl << "=== Vector de carreras ===" << std::endl;
    for (long unsigned int i = 0; i < arreglo.size();i++){
      arreglo.at(i).ImprimirCarrera();
      //std::cout << std::endl << "Vector [" << i << "] = " << arreglo.at(i).ImprimirCarrera()<< std::endl;
    }
}

//SORT ORDENA Vacantes 

void quickSortVacantes(std::vector<Carrera>& arreglo, int inicio, int final){
    int r;
    if(inicio<final)
    {
        r= partitionVacantes(arreglo, inicio, final);
        quickSortVacantes(arreglo,inicio,r);  
        quickSortVacantes(arreglo,r+1,final);
    }
}


int partitionVacantes(std::vector<Carrera>& arreglo, int inicio, int final){

    int x= arreglo.at(inicio).GetVacantesTotales();
    int i=inicio;
    int j;

    for(j=inicio+1; j<final; j++)
    {
        if(arreglo.at(j).GetVacantesTotales()<=x)
        {
            i=i+1;
            std::swap(arreglo.at(i),arreglo.at(j));
        }
    }
    std::swap(arreglo.at(i),arreglo.at(inicio));
    return i;
}

//SORT ORDENA Primer matriculado 

void quickSortPrimer(std::vector<Carrera>& arreglo, int inicio, int final){
    int r;
    if(inicio<final)
    {
        r= partitionPrimer(arreglo, inicio, final);
        quickSortPrimer(arreglo,inicio,r);  
        quickSortPrimer(arreglo,r+1,final);
    }
}


int partitionPrimer(std::vector<Carrera>& arreglo, int inicio, int final){

    int x= arreglo.at(inicio).GetPrim();
    int i=inicio;
    int j;

    for(j=inicio+1; j<final; j++)
    {
        if(arreglo.at(j).GetPrim()<=x)
        {
            i=i+1;
            std::swap(arreglo.at(i),arreglo.at(j));
        }
    }
    std::swap(arreglo.at(i),arreglo.at(inicio));
    return i;
}

std::vector<std::string> calcularPonderacion(int nem, int ranking, int matematicas, int lenguaje, int ciencias, int historia){
    //retorna como primer valor el {codigo carrera} y segundo valor {rut, ponderacion}
    //std::string texto;
    std::vector<std::string> salidaM;
    salidaM.push_back("NULL");
    std::ifstream admision;
    admision.open("data/admision.csv", std::ios::in); 

    if(admision)
    {
        for (std::string texto;; getline(admision,texto) )
        {
            std::vector<std::string> salida;

            std::vector<int> valores;
            valores = obtenerDatos(texto);
            if(valores.size() >= 9)
            {
                float ponderacion;
                float pnem = (float) valores.at(1)/100;
                float prank = (float) valores.at(2)/100;
                float pleng = (float) valores.at(3)/100;
                float pmat = (float) valores.at(4)/100;
                float phoc = (float) valores.at(5)/100;
                float minpostulacion = (float) valores.at(6);
                float vacantes = (float) valores.at(7);
                float pprimer = valores.at(8);
                float pultimo = valores.at(9);
                //std::cout << valores.at(0) << ", " << valores.at(1) << ", " << valores.at(2) << ", " << valores.at(3) << ", " << valores.at(4) << ", " << valores.at(5) << ", " << valores.at(6) << ", " << valores.at(7) << ", " << valores.at(8) << ", " << valores.at(9) << ", " << std::endl;

                ponderacion = nem*pnem + ranking* prank + matematicas*pmat + lenguaje * pleng;
                if(ciencias != 0 && historia == 0)
                {
                    ponderacion += ciencias*(float)(phoc);
                }
                else if(ciencias == 0 && historia != 0)
                {
                    ponderacion += historia*phoc;
                }
                else if(ciencias != 0 && historia != 0 && ciencias > historia)
                {
                    ponderacion += ciencias*phoc;
                }
                else if(ciencias != 0 && historia != 0 && historia > ciencias){
                    ponderacion += historia*phoc;
                }
                if(ponderacion > pultimo && ponderacion < pprimer && ponderacion > valores.at(6))
                {
                    salida.push_back(std::to_string(valores.at(0)));
                    salida.push_back(std::to_string(ponderacion));
                    admision.close();
                    std::cout << "inscribio a NEM: " << nem << " en la carrera: " << salida.at(0) << " con la ponderacion: " << salida.at(1) << std::endl;
                    return salida;  
                }
                else
                {
                    //cout << "carrera: " << valores.at(0) << " , " << ponderacion << "para el NEM: " << nem << " fallo al escribir esto" << endl;
                    //cout << ponderacion << endl;
                }
            }
            else
            {
                std::cout << "mal formateado el archivo de admision" << std::endl;
            }
        }
    }
    else{
        std::cout << "falta archivo de admision o formato no correcto " << std::endl;
        admision.close();
        return salidaM;
    }
    admision.close();
    return salidaM;
}
