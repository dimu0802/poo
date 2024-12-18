#ifndef LUPTA_H
#define LUPTA_H

#include <iostream>
#include "jucator.h"
#include "suprafata.h"
#include "constante.h"

class Lupta{
private:
    Jucator& p1;
    Jucator& p2;
    Suprafata suprafata;
public:
    explicit Lupta(Jucator& p1_dat, Jucator& p2_dat, Suprafata& suprafata_data);
    bool moment_al_jocului();
    void proceseaza_actiuni_egale(int actiune);
    void proceseaza_actiuni_diferite(int actiune1, int actiune2);
    
};

#endif