#ifndef EXCEPTIE_CAPAT_H
#define EXCEPTIE_CAPAT_H

#include "exceptie_baza.h"

class ExceptiePozitieCapat:public ExceptieBaza{
public:
    explicit ExceptiePozitieCapat(const std::string& mesaj_eroare)
        :ExceptieBaza("ExceptiePozitieCapat: "+mesaj_eroare){}
};

#endif
