#include <iostream>
#include "../include/lupta.h"

Lupta::Lupta(Jucator& p1_dat, Jucator& p2_dat, Suprafata& suprafata_data):
    p1(p1_dat), p2(p2_dat), suprafata(suprafata_data) {}

void Lupta::proceseaza_actiuni_egale(int actiune) {
    if (actiune == atac || actiune == ocolire) {
        std::cout << "Ambii jucatori au punctat!\n";
        p1.primeste_un_punct();
        p2.primeste_un_punct();
    } else if (actiune == parada) {
        std::cout << "Ambii jucatori au parat. Fiecare se retrage un pas.\n";
        p1.se_retrage_o_pozitie();
        p2.avanseaza_o_pozitie();
    }
    suprafata.suprafata_noua();
}

void Lupta::proceseaza_actiuni_diferite(int actiune1, int actiune2) {
    if ((actiune1 == atac && actiune2 == parada) || (actiune1 == ocolire && actiune2 == atac) || (actiune1 == parada && actiune2 == ocolire)) {
        std::cout << "A punctat Jucatorul 2!\n";
        p2.primeste_un_punct();
    } else {
        std::cout << "A punctat Jucatorul 1!\n";
        p1.primeste_un_punct();
    }
    suprafata.suprafata_noua();
}

bool Lupta::moment_al_jocului() {
    std::cout << "Va aflati intr-un moment de lupta! Fiecare jucator sa-si aleaga actiunea!\n";
    std::cout << "Jucatorul p1: ";
    int actiune1 = p1.alege_actiune();
    std::cout << "Jucatorul p2: ";
    int actiune2 = p2.alege_actiune();
    std::cout << "\n";

    if (actiune1 == actiune2) {
        proceseaza_actiuni_egale(actiune1);
    } else {
        proceseaza_actiuni_diferite(actiune1, actiune2);
    }

    return (actiune1 == 2 && actiune2 == 2) ? false : true;
}

