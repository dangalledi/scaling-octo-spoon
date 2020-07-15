#include "Carrera.h"
#include "funciones.h"
#include <vector>
#include <sstream>
#include <iostream>

Carrera::Carrera(){
    codigo = 0;
    nem = 0;
    ranking = 0;
    matematica = 0;
    lenguaje = 0;
    cieHist  = 0;
    ptMin = 0;
    vacantesTotales=0;
    vacantes = 0;
    prim = 0;
    ult = 0;
}

Carrera::Carrera( std::string datos ){
    std::vector<int> valores;
    std::stringstream ss(datos);
    std::string item;

    while (std::getline(ss, item, ',')) {
      int valor = atoi(item.c_str());
      valores.push_back(valor);
    }
    
    if(valores.size() >= 9){
      this->codigo = (float) valores.at(0);
      this->nem = (float) valores.at(1);
      this->ranking = (float) valores.at(2);
      this->matematica = (float) valores.at(3);
      this->lenguaje = (float) valores.at(4);
      this->cieHist = (float) valores.at(5);
      this->ptMin = (float) valores.at(6);
      this->vacantesTotales = (float) valores.at(7);
      this->vacantes = vacantesTotales;
      this->prim = (float) valores.at(8);
      this->ult = (float) valores.at(9);
    }
}

Carrera::~Carrera(){

}
int Carrera::GetCieHist() const {
    return cieHist;
}

void Carrera::SetCieHist(int cieHist) {
    this->cieHist = cieHist;
}

int Carrera::GetCodigo() const {
    return codigo;
}

void Carrera::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Carrera::GetLenguaje() const {
    return lenguaje;
}

void Carrera::SetLenguaje(int lenguaje) {
    this->lenguaje = lenguaje;
}

int Carrera::GetMatematica() const {
    return matematica;
}

void Carrera::SetMatematica(int matematica) {
    this->matematica = matematica;
}

int Carrera::GetNem() const {
    return nem;
}

void Carrera::SetNem(int nem) {
    this->nem = nem;
}

int Carrera::GetPrim() const {
    return prim;
}

void Carrera::SetPrim(int prim) {
    this->prim = prim;
}

int Carrera::GetPtMin() const {
    return ptMin;
}

void Carrera::SetPtMin(int ptMin) {
    this->ptMin = ptMin;
}

int Carrera::GetRanking() const {
    return ranking;
}

void Carrera::SetRanking(int ranking) {
    this->ranking = ranking;
}

int Carrera::GetUlt() const {
    return ult;
}

void Carrera::SetUlt(int ult) {
    this->ult = ult;
}

int Carrera::GetVacantesTotales() const {
    return vacantesTotales;
}

void Carrera::SetVacantesTotales(int vacantesTotales) {
    this->vacantesTotales = vacantesTotales;
}

int Carrera::GetVacantes() const {
    return vacantes;
}

void Carrera::SetVacantes(int vacantes) {
    this->vacantes = vacantes;
}
void Carrera::ImprimirCarrera( ){
    std::cout << "Codigo : " << codigo << std::endl;
    std::cout << "nem : " << nem << std::endl;
    std::cout << "ranking : " << ranking << std::endl;
    std::cout << "matematica : " << matematica << std::endl;
    std::cout << "lenguaje : " << lenguaje << std::endl;
    std::cout << "CieHist : " << cieHist << std::endl;
    std::cout << "Puntaje minimo de postulacion : " << ptMin << std::endl;
    std::cout << "Vacantes totales: " << vacantes << std::endl;
    std::cout << "Puntaje del primer matriculado : " << prim << std::endl;
    std::cout << "puntaje del ultimo matriculado : " << ult << std::endl;
    std::cout << "-------------------------------------------"  << std::endl;
}
   