#pragma once

#include <exception>
#include <string>

class ExceptiePozitieCapat:public std::exception {
private:
    std::string mesaj;

public:
    explicit ExceptiePozitieCapat(const std::string& mesaj_eroare)
        : mesaj(mesaj_eroare) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};
