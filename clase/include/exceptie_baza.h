#ifndef EXCEPTIE_BAZA_H
#define EXCEPTIE_BAZA_H

#include <exception>
#include <string>

class ExceptieBaza:public std::exception{
private:
    std::string mesaj;

public:
    explicit ExceptieBaza(const std::string& msg):mesaj(msg){}

    const char* what() const noexcept override{
        return mesaj.c_str();
    }

    virtual ~ExceptieBaza()=default;
};

#endif
