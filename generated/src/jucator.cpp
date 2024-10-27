#include <iostream>
#include "jucator.h"

Jucator::Jucator(const std::string& numedat, int pozitie_initiala, int numar_puncte_initial)
:nume(numedat), pozitie(pozitie_initiala), numar_puncte(numar_puncte_initial){} 

Jucator::Jucator(const Jucator& other)
:nume(other.nume), pozitie(other.pozitie), numar_puncte(other.numar_puncte){
    std::cout<<"s a apelat constructorul de copiere\n";
}

void Jucator::alegere_mutare(){
    std::cout<<"Alegeti in ce directie muti? [1-Inapoi(spre suprafata[0]] [2-Inainte(spre suprafata[11])]\n";
    int mutare;
    std::cin>>mutare;
    if(mutare==2){
        avanseaza_o_pozitie();
    }else if(mutare==1){
        se_retrage_o_pozitie();
    }
}

void Jucator::avanseaza_o_pozitie(){
    int pozitie_act=pozitie_actuala();
    pozitie_act++;
    actualizeaza_pozitie(pozitie_act);
}

void Jucator::se_retrage_o_pozitie(){
    int pozitie_act=pozitie_actuala();
    pozitie_act--;
    actualizeaza_pozitie(pozitie_act);
}

void Jucator::actualizeaza_pozitie(int pozitie_dorita){
    pozitie=pozitie_dorita;
}

int Jucator::alege_actiune(){
    std::cout<<"Alege actiunea dorita(ATAC[0], OCOLIRE DE PARADA[1], PARADA[2]: \n";
    int actiune_aleasa;
    std::cin>>actiune_aleasa;
    return actiune_aleasa;
}

void Jucator::primeste_un_punct(){
    numar_puncte++;
}

int Jucator::scor_actual(){return numar_puncte;}
int Jucator::pozitie_actuala(){return pozitie;}


void Jucator::revenire_pozitie_initiala(int pozitie_initiala){
    pozitie=pozitie_initiala;
}

Jucator::~Jucator(){}

bool Jucator::verificare_pozitie_capat(){
    int poz=pozitie_actuala();
    if(poz==0 || poz==11){
        return true;
    }
    else return false;
}
