#ifndef EXCEPTII_LOVITURA_DUBLA_H
#define EXCEPTII_LOVITURA_DUBLA_H

#include "exceptie_baza.h"

class ExceptieLovituraDubla : public ExceptieBaza {
public:
    explicit ExceptieLovituraDubla(const std::string& msg) : ExceptieBaza(msg) {}
};

#endif

