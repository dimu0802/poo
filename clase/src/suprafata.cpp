#include <iostream>
#include "../include/suprafata.h"

Suprafata::Suprafata(Jucator& p1_dat, Jucator& p2_dat):
    p1(p1_dat), p2(p2_dat){}

void Suprafata::initializeaza_suprafata(int poz1, int poz2) {
    suprafata={0};  
    suprafata[poz1]=1;
    suprafata[poz2]=2;
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

