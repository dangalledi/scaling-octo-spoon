#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <vector>

using namespace std;

class Estudiante {
public:
    Estudiante();
    Estudiante( vector<int> arreglo );
    virtual ~Estudiante();
    int GetRut();
    int GetNem();
    int GetRanking();    
    int GetMatematica();
    int GetLenguaje();
    int GetCiencias();
    int GetHistoria();
    void SetRut(int Rut);
    void SetNem(int Nem);
    void SetRanking(int Ranking);    
    void SetMatematica(int Matematica);
    void SetLenguaje(int Lenguaje);
    void SetCiencias(int Ciencias);
    void SetHistoria(int Historia);
    void ImprimirEstudiante( );
private:
    int rut;
    int nem;
    int ranking;
    int matematica;
    int lenguaje;
    int ciencias;
    int historia;
};

#endif /* ESTUDIANTE_H */
