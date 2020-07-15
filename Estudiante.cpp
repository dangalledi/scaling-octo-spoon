#include "Estudiante.h"
#include <vector>
#include <sstream>
#include <iostream>

Estudiante::Estudiante() {
    rut = 0;
    nem = 0;
    ranking = 0;
    matematica = 0;
    lenguaje = 0;
    ciencias  = 0;
    historia = 0;
}

Estudiante::Estudiante( std::string datos ){
    std::vector<int> valores;
    std::stringstream ss(datos);
    std::string item;

    while (std::getline(ss, item, ',')) {
      int valor = atoi(item.c_str());
      valores.push_back(valor);
    }
    
    if(valores.size() >= 6){
      this->rut = (float) valores.at(0);
      this->nem = (float) valores.at(1);
      this->ranking = (float) valores.at(2);
      this->matematica = (float) valores.at(3);
      this->lenguaje = (float) valores.at(4);
      this->ciencias = (float) valores.at(5);
      this->historia = (float) valores.at(6);
    }   
}

Estudiante::~Estudiante() {
  
}
int Estudiante::GetCiencias() const {
    return ciencias;
}

void Estudiante::SetCiencias(int ciencias) {
    this->ciencias = ciencias;
}

int Estudiante::GetHistoria() const {
    return historia;
}

void Estudiante::SetHistoria(int historia) {
    this->historia = historia;
}

int Estudiante::GetLenguaje() const {
    return lenguaje;
}

void Estudiante::SetLenguaje(int lenguaje) {
    this->lenguaje = lenguaje;
}

int Estudiante::GetMatematica() const {
    return matematica;
}

void Estudiante::SetMatematica(int matematica) {
    this->matematica = matematica;
}

int Estudiante::GetNem() const {
    return nem;
}

void Estudiante::SetNem(int nem) {
    this->nem = nem;
}

int Estudiante::GetRanking() const {
    return ranking;
}

void Estudiante::SetRanking(int ranking) {
    this->ranking = ranking;
}

int Estudiante::GetRut() const {
    return rut;
}

void Estudiante::SetRut(int rut) {
    this->rut = rut;
}
void Estudiante::ImprimirEstudiante()
{
    std::cout << "Rut : " << rut << std::endl;
    std::cout << "Nem : " << nem << std::endl;
    std::cout << "Ranking : " << ranking << std::endl;
    std::cout << "Matematica : " << matematica << std::endl;
    std::cout << "Lenguaje : " << lenguaje << std::endl;
    std::cout << "Ciencias : " << ciencias << std::endl;
    std::cout << "Historia : " << historia << std::endl;
    std::cout << "-------------------------------------------"  << std::endl;
} 