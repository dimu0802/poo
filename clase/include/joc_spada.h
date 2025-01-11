#ifndef JOC_SPADA_H
#define JOC_SPADA_H

#include "joc.h"

class Joc_Spada:public Joc{
public:
    Joc_Spada(const std::string& nume1, const std::string& nume2);
    //explicit Joc_Spada(const Joc& joc);

    std::unique_ptr<Joc> clone() const override;
    bool moment_al_jocului() override;
    void start() override;
    void proceseaza_actiuni_egale() override;
    void proceseaza_actiuni_egale_spada(int actiune);
    void proceseaza_actiuni_diferite(int actiune1, int actiune2) override;
    bool validare_lovitura(int punct_lovitura) override;
    void egalitate4();

};

#endif
