#ifndef CARRERA_H
#define CARRERA_H
#include <iostream>
#include <vector>

using namespace std;

class Carrera {
public:
    Carrera();
    Carrera(std::vector<int> arreglo);
    virtual ~Carrera();
    int GetCodigo();
    int GetNem();
    int GetRanking();    
    int GetMatematica();
    int GetLenguaje();
    int GetCieHist();
    int GetPtMin();
    int GetVacantes();
    int GetPrim();
    int GetUlt();
    void SetCodigo(int Codigo);
    void SetNem(int Nem);
    void SetRanking(int Ranking);    
    void SetMatematica(int Matematica);
    void SetLenguaje(int Lenguaje);
    void SetCieHist(int CieHist);
    void SetPtMin(int PtMin);
    void SetVacantes(int Vacantes);
    void SetPrim(int Prim);
    void SetUlt(int Ult);
    void ImprimirCarrera( );
private:
    int codigo;
    int nem;
    int ranking;
    int matematica;
    int lenguaje;
    int cieHist;
    int ptMin;
    int vacantes;
    int prim;
    int ult;
};

#endif /* CARRERA_H */
