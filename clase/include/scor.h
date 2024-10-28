#ifndef SCOR_H
#define SCOR_H

#include <iostream>
#include "jucator.h"

class Scor{
private:
    Jucator& p1;
    Jucator& p2;
public:
    explicit Scor(Jucator& p1_dat, Jucator& p2_dat);
    friend std::ostream& operator<<(std::ostream& os, const Scor& scor){
        os<<"Scorul este: "<<scor.p1.scor_actual()<<"-"<<scor.p2.scor_actual()<<"\n\n";
        return os;
    }
};

#endif