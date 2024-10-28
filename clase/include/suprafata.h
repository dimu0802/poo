#ifndef SUPRAFATA_H
#define SUPRAFATA_H

#include <iostream>
#include <array>
#include "jucator.h"

class Suprafata{
private:
    std::array<int, 12> suprafata;
    Jucator& p1;
    Jucator& p2;
public:
    explicit Suprafata(Jucator& p1_dat, Jucator& p2_dat);
    void suprafata_noua();
    void afisare_suprafata_actuala();
    void resetare_suprafata();
    friend std::ostream& operator<<(std::ostream& os, const Suprafata& sup){
        os<<"suprafata de lupta pentru acest meci: \n";
        
        for(size_t i=0; i<sup.suprafata.size(); i++){
            if(sup.suprafata[i]==0){
                os<<"[__]";
            }
            else if(sup.suprafata[i]==1){
                os<<"[ p1 ]";
            }else if(sup.suprafata[i]==2){
                os<<"[ p2 ]";
            }
        }
        os<<"[ p2 ]";
        return os;
    }
};

#endif