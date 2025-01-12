#ifndef LOBBY_H
#define LOBBY_H
#include "joc.h"
#include "joc_spada.h"
#include "constante.h"
#include "exceptie_baza.h"
#include "exceptie_input.h"
#include "joc_arma_conventionala.h"
#include "reguli_arma.h"
#include "reguli_floreta.h"
#include "reguli_sabie.h"
#include <memory>

class Lobby {
    std::string nume1;
    std::string nume2;
    int arma_aleasa;
    std::unique_ptr<Joc> joc_actual;
public:
    Lobby() : nume1(""), nume2(""), arma_aleasa(0), joc_actual(nullptr){}
    void start_joc();
    void alegere_arma();
    void nume_jucatori();

    void swap(Lobby& other) noexcept;

    Lobby& operator=(const Lobby& other);
};

#endif