#ifndef EXCEPTII_INPUT_INVALID_H
#define EXCEPTII_INPUT_INVALID_H

#include "exceptie_baza.h"

class ExceptieInputInvalid:public ExceptieBaza{
public:
    explicit ExceptieInputInvalid(const std::string& msg):ExceptieBaza(msg){}

    
};

#endif

