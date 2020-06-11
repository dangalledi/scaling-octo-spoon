#include "Estudiante.h"
#include <vector>

Estudiante::Estudiante() {
    rut = 0;
    nem = 0;
    ranking = 0;
    matematica = 0;
    lenguaje = 0;
    ciencias  = 0;
    historia = 0;
}

Estudiante::Estudiante( vector<int> arreglo ){
    std::vector<int> valores;    // esto esta mal tiene que ir afuerita :C 
    valores = obtenerDatos(texto);
    rut = Rut;
    nem = Nem;
    ranking = Ranking;
    matematica = Matematica;
    lenguaje = Lenguaje;
    ciencias = Ciencias;
    historia = Historia;
}

Estudiante::~Estudiante() {
}
int Estudiante::GetRut(){
  return rut ;
}
int Estudiante::GetNem(){
  return nem ;
}
int Estudiante::GetRanking(){
  return ranking ;
}
int Estudiante::GetMatematica(){
  return matematica ;
}
int Estudiante::GetLenguaje(){
  return lenguaje ;
}
int Estudiante::GetCiencias(){
  return ciencias ;
}
int Estudiante::GetHistoria(){
  return historia ;
}
void Estudiante::SetRut(int Rut){
  this -> rut = Rut ;
}
void Estudiante::SetNem(int Nem){
  this -> nem = Nem ;
}
void Estudiante::SetRanking(int Ranking){
  this -> ranking = Ranking ;
}
void Estudiante::SetMatematica(int Matematica){
  this -> matematica = Matematica ;
}
void Estudiante::SetLenguaje(int Lenguaje){
  this -> lenguaje = Lenguaje ;
}
void Estudiante::SetCiencias(int Ciencias){
  this -> ciencias = Ciencias ;
}
void Estudiante::SetHistoria(int Historia){
  this -> historia = Historia ;
}
void Estudiante::ImprimirEstudiante()
{
    cout << "rut : " << rut << endl;
    cout << "nem : " << nem << endl;
    cout << "ranking : " << ranking << endl;
    cout << "matematica : " << matematica << endl;
    cout << "lenguaje : " << lenguaje << endl;
    cout << "ciencias : " << ciencias << endl;
    cout << "historia : " << historia << endl;
} 