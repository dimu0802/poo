
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

int main(){

    try{
        std::cout<<"\n\n===================================\n"
                <<"FENCING DUEL-OLYMPIC GLORY\n"
                <<"Format: Player vs Player\n"
                <<"===================================\n\n"
                <<"\nDupa ce ti-ai dedicat o viata intreaga\n"
                <<"acestui sport, ai reusit sa ajungi in finala olimpica! Felicitari!\n"
                <<"Acum urmeaza cel mai important meci al tau, cel care te poate propulsa\n"
                <<"in istoria sportului tau. Crezi ca faci fata provocarii?\n\n"
                <<"===================================\n";

        Lobby lobby;
        lobby.start_joc("reguli/floreta.txt", "reguli/sabie.txt", "reguli/spada.txt");
    }catch(const ExceptieInputInvalid& ex){
        std::cerr<<"Eroare de input: "<<ex.what()<<std::endl;
    }catch(const std::exception& ex){
        std::cerr<<"Eroare generala: "<<ex.what()<<std::endl;
    }

    return 0;
}