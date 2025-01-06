#include <iostream>
#include "../include/suprafata.h"

Suprafata::Suprafata(Jucator& p1_dat, Jucator& p2_dat):
    p1(p1_dat), p2(p2_dat){}

void Suprafata::initializeaza_suprafata(int poz1, int poz2){
    suprafata.fill(0);
    if(poz1>=0 && poz1<lungime_plansa){
        suprafata[poz1]=1;
    }else{
        std::cerr<<"Eroare: Pozitia jucatorului 1 este invalida: "<<poz1<<"\n";
    }
    if(poz2>=0 && poz2<lungime_plansa){
        suprafata[poz2]=2;
    }else{
        std::cerr<<"Eroare: Pozitia jucătorului 2 este invalida: "<<poz2<<"\n";
    }
}


void Suprafata::suprafata_noua(){
    int poz1=p1.pozitie_actuala();
    int poz2=p2.pozitie_actuala();
    initializeaza_suprafata(poz1, poz2);
}

void Suprafata::resetare_suprafata(){
    int poz1=4;
    int poz2=7;
    p1.revenire_pozitie_initiala(poz1);
    p2.revenire_pozitie_initiala(poz2);
    initializeaza_suprafata(poz1, poz2);
}

