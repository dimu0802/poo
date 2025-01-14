#ifndef JOC_H
#define JOC_H

#include "jucator.h"
#include "suprafata.h"
#include "constante.h"
#include "exceptie_baza.h"
#include "exceptie_capat.h"
#include "statistici.h"
#include <memory>

class Joc{
protected:
    static const int scor_maxim; 
    static const int pozitie_initiala_p1; 
    static const int pozitie_initiala_p2; 

    Jucator p1;
    Jucator p2;
    Suprafata suprafata;
    Statistici statistici;
public:

    Joc(const std::string& nume1, const std::string& nume2, 
        const std::string& reguli_fisier, int pozitie1 = 4, int pozitie2 = 7, 
        int puncte1 = 0, int puncte2 = 0);
    virtual ~Joc() = default;

    virtual std::unique_ptr<Joc> clone() const=0;
    virtual void start();
    void continua();

    virtual void proceseaza_actiuni_egale()=0;

protected:

    std::string reguli_fisier;
    void jucator_la_capat();
    void continuare_moment_lupta();

    void afiseaza_reguli();
    bool verificare_moment_lupta();
    bool verificare_meci_incheiat();
    void afisare_tinta();

    virtual void proceseaza_actiuni_diferite(int actiune1, int actiune2)=0;
    virtual bool moment_al_jocului()=0;
    virtual bool validare_lovitura(int punct_lovitura)=0;

    void proceseaza_actiuni_egale_comune();
private: 
    bool statistici_afisate=false;
    bool castigator_afisat=false; 
};

#endif



