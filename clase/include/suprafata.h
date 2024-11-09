#ifndef SUPRAFATA_H
#define SUPRAFATA_H

#include <iostream>
#include <array>
#include "jucator.h"
#include "constante.h"

class Suprafata{
private:
    std::array<int, lungime_plansa> suprafata;
    Jucator& p1;
    Jucator& p2;
    void initializeaza_suprafata(int poz1, int poz2);
public:
    explicit Suprafata(Jucator& p1_dat, Jucator& p2_dat);
    void suprafata_noua();
    void resetare_suprafata();
    friend std::ostream& operator<<(std::ostream& os, const Suprafata& sup){
        os<<"Pozitionarea jucatorilor: \n";
        
        for(size_t i=0; i<lungime_plansa; i++){
            if(sup.suprafata[i]==0){
                os<<"[__]";
            }
            else if(sup.suprafata[i]==1){
                os<<"[ p1 ]";
            }else if(sup.suprafata[i]==2){
                os<<"[ p2 ]";
            }
        }
        os<<"\n\n";
        return os;
    }
};

#endif