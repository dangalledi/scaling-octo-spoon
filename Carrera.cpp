#include "Carrera.h"
#include <vector>

    Carrera::Carrera(){
    codigo = 0;
    nem = 0;
    ranking = 0;
    matematica = 0;
    lenguaje = 0;
    cieHist  = 0;
    vacantes = 0;
    prim = 0;
    ult = 0;
    }
    Carrera::Carrera( vector<int> arreglo ){
      codigo = (float) valores.at(1)/100;;
      nem = (float) valores.at(2)/100;;
      ranking = (float) valores.at(3)/100;;
      matematica = (float) valores.at(4)/100;;
      lenguaje = (float) valores.at(5)/100;;
      cieHist = (float) valores.at(6)/100;;
      vacantes = Vacantes;
      prim = Prim;
      ult = Ult;
    }
    Carrera::~Carrera(){

    }
    int Carrera::GetCodigo(){
      return codigo;
    }
    int Carrera::GetNem(){
      return nem;
    }
    int Carrera::GetRanking(){
      return ranking;
    }   
    int Carrera::GetMatematica(){
      return matematica;
    }
    int Carrera::GetLenguaje(){
      return lenguaje;
    }
    int Carrera::GetCieHist(){
      return cieHist;
    }
    int Carrera::GetPtMin(){
      return ptMin;
    }
    int Carrera::GetVacantes(){
      return vacantes;
    }
    int Carrera::GetPrim(){
      return prim;
    }
    int Carrera::GetUlt(){
      return ult;
    }
    void Carrera::SetCodigo(int Codigo){
      this-> codigo = Codigo ;
      }
    void Carrera::SetNem(int Nem){
      this-> nem = Nem ;
      }
    void Carrera::SetRanking(int Ranking){
      this-> ranking = Ranking ;
      }    
    void Carrera::SetMatematica(int Matematica){
      this-> matematica = Matematica ;
      }
    void Carrera::SetLenguaje(int Lenguaje){
      this-> lenguaje = Lenguaje ;
      }
    void Carrera::SetCieHist(int CieHist){
      this-> cieHist = CieHist ;
      }
    void Carrera::SetPtMin(int PtMin){
      this-> ptMin = PtMin ;
      }
    void Carrera::SetVacantes(int Vacantes){
      this-> vacantes = Vacantes ;
      }
    void Carrera::SetPrim(int Prim){
      this-> prim = Prim ;
      }
    void Carrera::SetUlt(int Ult){
      this-> ult = Ult ;
      }
    void Carrera::ImprimirCarrera( ){
      
      cout << "codigo : " << codigo << endl;
      cout << "nem : " << nem << endl;
      cout << "ranking : " << ranking << endl;
      cout << "matematica : " << matematica << endl;
      cout << "lenguaje : " << lenguaje << endl;
      cout << "cieHist : " << cieHist << endl;
      cout << "ptMin : " << ptMin << endl;
      cout << "vacantes : " << vacantes << endl;
      cout << "prim : " << prim << endl;
      cout << "ult : " << ult << endl;
      
      }