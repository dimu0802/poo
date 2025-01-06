#ifndef LOBBY_H
#define LOBBY_H
#include "joc.h"
#include "joc_floreta.h"
#include "joc_sabie.h"
#include "joc_spada.h"
#include "constante.h"
#include "exceptii.h"
#include <memory>

class Lobby {
    std::string nume1;
    std::string nume2;
    int arma_aleasa;
    std::unique_ptr<Joc> joc_actual;
public:
    void start_joc(const std::string& reguli_floreta, const std::string& reguli_sabie, const std::string& reguli_spada);
    void alegere_arma(const std::string& reguli_floreta, const std::string& reguli_sabie, const std::string& reguli_spada);
    void nume_jucatori();
    void afisare_reguli(const std::string& fisier);
};

#endif
