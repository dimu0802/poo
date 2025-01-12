#ifndef STATISTICI_H
#define STATISTICI_H

#include <iostream>
#include <map>
#include <string>

class Statistici{
private:
    struct JucatorStat{
        int atacuri=0;
        int parade=0;
        int ocoliri=0;
        int avansari=0;
        int retrageri=0;
    };
    std::map<std::string, JucatorStat> statistici;

public:
    void inregistreaza_actiune(const std::string& nume_jucator, int actiune, int pozitie_curenta, int pozitie_adversar);

    std::string determina_agresivitate(const JucatorStat& stat) const;
    std::string determina_stil_joc(const JucatorStat& stat) const;
    void afisare_statistici() const;
};

#endif
