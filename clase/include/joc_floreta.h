#ifndef JOC_FLORETA_H
#define JOC_FLORETA_H

#include "joc.h"
#include <memory>

class Joc_Floreta:public Joc{
public:
    Joc_Floreta(const std::string& nume1, const std::string& nume2);
    explicit Joc_Floreta(const Joc& joc);

    void start() override;

    void proceseaza_actiuni_egale();
    void proceseaza_actiuni_diferite(int actiune1, int actiune2) override;
    bool validare_lovitura(int punct_lovitura) override;
    bool moment_al_jocului() override;
};

#endif
