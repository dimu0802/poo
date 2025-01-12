#include <iostream>
#include <memory>
#include "../include/lobby.h"

void Lobby::start_joc(){
    nume_jucatori();
    std::cout<<"\nAcum că știm numele adversarilor, să alegem arma cu care vă veți confrunta.\n";
    alegere_arma();

    if (joc_actual){
        joc_actual->start();
        std::cout<<"Se creează o copie a jocului curent...\n";
        auto copie_joc=joc_actual->clone();
    }
}

void Lobby::nume_jucatori(){
    std::cout<<"\nSportivi, alegeți-vă numele:\n";
    std::cout<<"Numele Jucătorului 1: ";
    std::cin>>nume1;
    std::cout<<"Numele Jucătorului 2: ";
    std::cin>>nume2;
}

void Lobby::alegere_arma(){
    while (true){
        try{
            std::cout<<"Alegeți proba de scrimă în care doriți să participați!\n";
            std::cout<<"FLORETĂ   SABIE   SPADĂ\n";
            std::cout<<"   1        2       3\n";
            std::cin>>arma_aleasa;

            if(arma_aleasa<1 || arma_aleasa>3){
                throw ExceptieInputInvalid("Arma aleasă este invalidă! Trebuie să fie între 1 și 3.");
            }

            if(arma_aleasa==1){
                auto reguli=std::make_shared<Reguli_Arma_Floreta>("reguli/floreta.txt");
                joc_actual=std::make_unique<Joc_Arma_Conventionala>(nume1, nume2, reguli);
            }else if(arma_aleasa==2){
                auto reguli=std::make_shared<Reguli_Arma_Sabie>("reguli/sabie.txt");
                joc_actual=std::make_unique<Joc_Arma_Conventionala>(nume1, nume2, reguli);
            }else{
                joc_actual=std::make_unique<Joc_Spada>(nume1, nume2);
            }

            break;
        }catch(const ExceptieInputInvalid& ex){
            std::cerr<<ex.what()<<"\n";
        }
    }
}


Lobby& Lobby::operator=(const Lobby& other){
    if (this==&other){
        return *this;
    }

    std::unique_ptr<Joc> copie_joc=other.joc_actual ? other.joc_actual->clone() : nullptr;

    nume1=other.nume1;
    nume2=other.nume2;
    arma_aleasa=other.arma_aleasa;

    joc_actual=std::move(copie_joc);

    return *this;
}

void Lobby::swap(Lobby& other) noexcept{
    using std::swap;
    swap(nume1, other.nume1);
    swap(nume2, other.nume2);
    swap(arma_aleasa, other.arma_aleasa);
    swap(joc_actual, other.joc_actual);
}
