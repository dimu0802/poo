#ifndef EXCEPTIE_LOVITURA_DUBLA_H
#define EXCEPTIE_LOVITURA_DUBLA_H

#include <exception>
#include <string>

class ExceptieLovituraDubla : public std::exception{
private:
    std::string mesaj;
public:
    explicit ExceptieLovituraDubla(const std::string& msg):mesaj(msg){}

    const char* what() const noexcept override{
        return mesaj.c_str();
    }
};

#endif
