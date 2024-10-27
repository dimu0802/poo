#ifndef JOC_H
#define JOC_H

#include "jucator.h"
#include "lupta.h"
#include "suprafata.h"
#include "scor.h"


class Joc{
private:
    Jucator p1;
    Jucator p2;
    Suprafata suprafata;
    Scor scor;
    Lupta moment;
public:
    Joc(const std::string& nume1, const std::string& nume2, int pozitie1, int pozitie2, int puncte1 = 0, int puncte2 = 0);
    void start();
    void continua();
    bool verificare_moment_lupta(int poz1, int poz2);
    bool verificare_meci_incheiat(int puncte1, int puncte2);
};

#endif
