#ifndef LUPTA_H
#define LUPTA_H

#include <iostream>
#include "jucator.h"
#include "suprafata.h"

class Lupta{
private:
    Jucator& p1;
    Jucator& p2;
    Suprafata suprafata;
public:
    explicit Lupta(Jucator& p1_dat, Jucator& p2_dat, Suprafata& suprafata_data);
    int moment_al_jocului();

};

#endif