#include <iostream>
#include <memory>
#include "../include/lobby.h"

void Lobby::start_joc() {
    nume_jucatori();
    std::cout << "\nAcum că știm numele adversarilor, să alegem arma cu care vă veți confrunta.\n";
    alegere_arma();

    if (joc_actual){
        joc_actual->start();      
    }
}

void Lobby::nume_jucatori(){
    std::cout << "\nSportivi, alegeți-vă numele:\n";
    std::cout << "Numele Jucătorului 1: ";
    std::cin >> nume1;
    std::cout << "Numele Jucătorului 2: ";
    std::cin >> nume2;
}

void Lobby::alegere_arma() {
    std::cout << "Alegeți proba de scrimă în care doriți să participați!\n";
    std::cout << "FLORETĂ   SABIE   SPADĂ\n";
    std::cout << "   1        2       3\n";
    std::cin >> arma_aleasa;

    if (arma_aleasa < 1 || arma_aleasa > 3) {
        throw ExceptieInputInvalid("Arma aleasă este invalidă! Trebuie să fie între 1 și 3.");
    }

    if (arma_aleasa == 1) {
        joc_actual = std::make_unique<Joc_Floreta>(nume1, nume2);
    } else if (arma_aleasa == 2) {
        joc_actual = std::make_unique<Joc_Sabie>(nume1, nume2);
    } else {
        joc_actual = std::make_unique<Joc_Spada>(nume1, nume2);
    }
}
