#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class ExceptieInputInvalid : public std::exception{
private:
    std::string mesaj;
public:
    explicit ExceptieInputInvalid(const std::string& mesaj_eroare):mesaj(mesaj_eroare){}

    const char* what() const noexcept override{ 
        return mesaj.c_str();
    }
};

#endif
