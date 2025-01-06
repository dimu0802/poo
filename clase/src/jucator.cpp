

#include <iostream>
#include "../include/jucator.h"

Jucator::Jucator(const std::string& numedat, int pozitie_initiala, int numar_puncte_initial)
:nume(numedat), pozitie(pozitie_initiala), numar_puncte(numar_puncte_initial){} 

Jucator::Jucator(const Jucator& other)
:nume(other.nume), pozitie(other.pozitie), numar_puncte(other.numar_puncte){}

void Jucator::alegere_mutare(){
    std::cout<<"Alegeti in ce directie muti? ([1-Inapoi(spre suprafata[0]] [2-Inainte(spre suprafata[11])]\n";
    int mutare;
    std::cin>>mutare;

    if(mutare!=1 && mutare!=2){
        throw ExceptieInputInvalid("Mutarea aleasa este invalida! Trebuie sa fie 1 (inapoi) sau 2 (inainte).");
    }

    if(mutare==2){
        avanseaza_o_pozitie();
    }else if(mutare==1){
        se_retrage_o_pozitie();
    }
}

void swap(Jucator& a, Jucator& b) noexcept{
    using std::swap;
    swap(a.nume, b.nume);
    swap(a.pozitie, b.pozitie);
    swap(a.numar_puncte, b.numar_puncte);
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
    std::cout<<"Alege actiunea dorita (ATAC[1], OCOLIRE DE PARADA[2], PARADA[3]): \n";
    int actiune_aleasa;
    std::cin>>actiune_aleasa;

    if (actiune_aleasa!=1 && actiune_aleasa!=2 && actiune_aleasa!=3){
        throw ExceptieInputInvalid("Actiunea aleasa este invalida! Trebuie sa fie 1 (ATAC), 2 (OCOLIRE DE PARADA), sau 3 (PARADA).");
    }

    return actiune_aleasa;
}

void Jucator::primeste_un_punct(){
    numar_puncte++;
}

// void Jucator::scade_un_punct(){
//     numar_puncte--;
// }

int Jucator::scor_actual(){return numar_puncte;}
int Jucator::pozitie_actuala() const{return pozitie;}
std::string Jucator::get_nume() const{return nume;}

void Jucator::revenire_pozitie_initiala(int pozitie_initiala){
    pozitie=pozitie_initiala;
}

Jucator::~Jucator(){}

bool Jucator::verificare_pozitie_capat(){
    int poz=pozitie_actuala();
    if(poz==capat_dreapta || poz==capat_stanga){
        return true;
    }
    else return false;
}


