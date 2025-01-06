#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/lobby.h"

void Lobby::start_joc(const std::string& reguli_floreta, const std::string& reguli_sabie, const std::string& reguli_spada){
    nume_jucatori();
    std::cout<<"\nAcum ca stim numele adversarilor, sa alegem arma cu care va veti confrunta";
    alegere_arma(reguli_floreta, reguli_sabie, reguli_spada);
}

void Lobby::nume_jucatori(){
    std::cout<<"\nSportivi, alegeti-va numele:\n";
    std::cout<<"Numele Jucatorului 1: ";
    std::cin>>nume1;
    std::cout<<"Numele Jucatorului 2: ";
    std::cin>>nume2;
}

void Lobby::alegere_arma(const std::string &reguli_floreta, const std::string &reguli_sabie, const std::string &reguli_spada){
    std::cout<<"Alegeti proba de scrima in care doriti sa participati!\n";
    std::cout<<"FLORETA   SABIE   SPADA\n";
    std::cout<<"   1        2       3\n";
    std::cin>>arma_aleasa;

    if(arma_aleasa<1||arma_aleasa>3){
        throw ExceptieInputInvalid("Arma aleasa este invalida! Trebuie sa fie intre 1 si 3.");
    }

    if(arma_aleasa==1){
        afisare_reguli(reguli_floreta);
        joc_actual=std::make_unique<Joc_Floreta>(nume1, nume2);
    }else if(arma_aleasa==2) {
        afisare_reguli(reguli_sabie);
        joc_actual=std::make_unique<Joc_Sabie>(nume1, nume2);
    }else{
        afisare_reguli(reguli_spada);
        joc_actual=std::make_unique<Joc_Spada>(nume1, nume2);
    }

    if(joc_actual){
        joc_actual->start();
    }
}

void Lobby::afisare_reguli(const std::string& fisier){
    std::vector<std::string> reguli;
    std::ifstream fin(fisier);
    if(!fin){
        std::cout<<"Eroare la deschiderea fișierului.\n";
        return;
    }
    std::string linie;
    while(std::getline(fin, linie)){
        reguli.push_back(linie);
    }
    fin.close();
    for (const auto& regula:reguli){
        std::cout<<regula<<"\n";
    }
}



