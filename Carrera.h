#ifndef CARRERA_H
#define CARRERA_H
#include <vector>
#include <iostream>


class Carrera {
public:
    Carrera();
    Carrera(std::string datos);
    virtual ~Carrera();
    int GetCieHist() const;
    void SetCieHist(int cieHist);
    int GetCodigo() const;
    void SetCodigo(int codigo);
    int GetLenguaje() const;
    void SetLenguaje(int lenguaje);
    int GetMatematica() const;
    void SetMatematica(int matematica);
    int GetNem() const;
    void SetNem(int nem);
    int GetPrim() const;
    void SetPrim(int prim);
    int GetPtMin() const;
    void SetPtMin(int ptMin);
    int GetRanking() const;
    void SetRanking(int ranking);
    int GetUlt() const;
    void SetUlt(int ult);
    int GetVacantesTotales() const;
    void SetVacantesTotales(int vacantesTotales);
    int GetVacantes() const;
    void SetVacantes(int vacantes);
    void ImprimirCarrera( );
private:
    int codigo;
    int nem;
    int ranking;
    int matematica;
    int lenguaje;
    int cieHist;
    int ptMin;
    int vacantesTotales;
    int vacantes;
    int prim;
    int ult;
};

#endif /* CARRERA_H */
