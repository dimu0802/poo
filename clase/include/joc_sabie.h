#ifndef JOC_SABIE_H
#define JOC_SABIE_H

#include "joc.h"

class Joc_Sabie:public Joc{
public:
    Joc_Sabie(const std::string& nume1, const std::string& nume2);
    explicit Joc_Sabie(const Joc& joc);

    std::unique_ptr<Joc> clone() const override;

    void proceseaza_actiuni_egale();
    void proceseaza_actiuni_diferite(int actiune1, int actiune2) override;
    bool moment_al_jocului() override;
    bool validare_lovitura(int punct_lovitura) override;
};

#endif
