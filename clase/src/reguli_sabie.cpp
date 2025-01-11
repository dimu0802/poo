#include "../include/reguli_sabie.h"
#include <iostream>
#include <fstream>

void Reguli_Arma_Sabie::afisare_reguli() const {
    std::ifstream fin(reguli_fisier);
    if (!fin) {
        std::cerr << "Eroare la deschiderea fișierului de reguli: " << reguli_fisier << "\n";
        return;
    }
    std::string linie;
    while (std::getline(fin, linie)) {
        std::cout << linie << "\n";
    }
}

std::string Reguli_Arma_Sabie::get_cale_fisier() const {
    return reguli_fisier;
}

bool Reguli_Arma_Sabie::validare_lovitura(int punct_lovitura) const {
    return punct_lovitura >= 3 && punct_lovitura <= 4;
}
