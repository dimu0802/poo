#include <iostream>
#include <string>
#include "constante.h"
#include "exceptie_baza.h"
#include "exceptie_input.h"
#include "exceptie_capat.h"
#include "exceptie_lovitura_dubla.h"
#include "joc.h"
#include "jucator.h"
#include "suprafata.h"
#include "lobby.h"
#include "joc_spada.h"
#include "joc_arma_conventionala.h"
#include "reguli_arma.h"
#include "reguli_floreta.h"
#include "reguli_sabie.h"
#include "statistici.h"

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
        lobby.start_joc();
    }catch(const ExceptieBaza& ex){
        std::cerr<<"Eroare specifica: "<<ex.what()<<std::endl;
    }catch(const std::exception& ex){
        std::cerr<<"Eroare generala: "<<ex.what()<<std::endl;
    }

    return 0;
}