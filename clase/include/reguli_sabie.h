
#ifndef REGULI_ARMA_SABIE_H
#define REGULI_ARMA_SABIE_H

#include "reguli_arma.h"

class Reguli_Arma_Sabie:public Reguli_Arma{
public:
    explicit Reguli_Arma_Sabie(const std::string& cale) : Reguli_Arma(cale){}

    void afisare_reguli() const override;
    std::string get_cale_fisier() const override;
    bool validare_lovitura(int punct_lovitura) const override;
};

#endif
