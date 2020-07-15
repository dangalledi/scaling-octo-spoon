#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <vector>
#include <iostream>


class Estudiante {
public:
    Estudiante();
    Estudiante(std::string datos );
    virtual ~Estudiante();
    int GetRut()const;
    int GetNem()const;
    int GetRanking()const;    
    int GetMatematica()const;
    int GetLenguaje()const;
    int GetCiencias()const;
    int GetHistoria()const;
    void SetRut(int Rut);
    void SetNem(int Nem);
    void SetRanking(int Ranking);    
    void SetMatematica(int Matematica);
    void SetLenguaje(int Lenguaje);
    void SetCiencias(int Ciencias);
    void SetHistoria(int Historia);
    void ImprimirEstudiante();
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