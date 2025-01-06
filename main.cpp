
#include <iostream>
#include <string>
#include "constante.h"
#include "exceptii.h"
#include "joc.h"
#include "jucator.h"
#include "suprafata.h"
#include "lobby.h"
#include "joc_floreta.h"
#include "joc_sabie.h"
#include "joc_spada.h"

int main() {

    
    try {
        std::cout<<"\nTest pentru metoda clone() în Joc_Sabie:\n";
        std::unique_ptr<Joc> joc_sabie=std::make_unique<Joc_Sabie>("Jucator1", "Jucator2");
        std::unique_ptr<Joc> copie_joc=joc_sabie->clone();

        std::cout<<"Copia jocului este de tip: " << typeid(*copie_joc).name()<<"\n";
    } catch (const std::exception& ex){
        std::cerr<<"Eroare: "<<ex.what()<<std::endl;
    }

    try {
        std::cout << "\n\n===================================\n"
                  << "FENCING DUEL-OLYMPIC GLORY\n"
                  << "Format: Player vs Player\n"
                  << "===================================\n\n"
                  << "\nDupa ce ti-ai dedicat o viata intreaga\n"
                  << "acestui sport, ai reusit sa ajungi in finala olimpica! Felicitari!\n"
                  << "Acum urmeaza cel mai important meci al tau, cel care te poate propulsa\n"
                  << "in istoria sportului tau. Crezi ca faci fata provocarii?\n\n"
                  << "===================================\n";

        Lobby lobby;
        lobby.start_joc("reguli/floreta.txt", "reguli/sabie.txt", "reguli/spada.txt");
    } catch (const ExceptieInputInvalid& ex) {
        std::cerr << "Eroare de input: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Eroare generala: " << ex.what() << std::endl;
    }

    return 0;
}