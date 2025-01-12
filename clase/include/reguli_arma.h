#ifndef REGULI_ARMA_H
#define REGULI_ARMA_H

#include <string>
#include <fstream>
#include <iostream>

class Reguli_Arma{
protected:
    std::string reguli_fisier;

public:
    explicit Reguli_Arma(const std::string& fisier):reguli_fisier(fisier){}
    virtual ~Reguli_Arma()=default;

    virtual bool validare_lovitura(int punct_lovitura) const=0;

    virtual void afisare_reguli() const{
        std::ifstream fin(reguli_fisier);
        if (!fin){
            std::cerr<<"Eroare la deschiderea: "<<reguli_fisier<<"\n";
            return;
        }

        std::string linie;
        while (std::getline(fin, linie)){
            std::cout<<linie<<"\n";
        }
        fin.close();
    }

    virtual std::string get_cale_fisier() const=0;
};

#endif
