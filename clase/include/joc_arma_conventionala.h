#ifndef JOC_ARMA_CONVENTIONALA_H
#define JOC_ARMA_CONVENTIONALA_H

#include "joc.h"
#include "reguli_arma.h"
#include <memory>

class Joc_Arma_Conventionala:public Joc{
    std::shared_ptr<Reguli_Arma> reguli;

public:
    Joc_Arma_Conventionala(const std::string& nume1, const std::string& nume2,
                           std::shared_ptr<Reguli_Arma> reguli_arma);

    void start() override;
    void proceseaza_actiuni_diferite(int actiune1, int actiune2) override;
    bool moment_al_jocului() override;
    bool validare_lovitura(int punct_lovitura) override;
    void proceseaza_actiuni_egale() override;

    std::unique_ptr<Joc> clone() const override;
};

#endif

