#include "../include/joc_arma_conventionala.h"
#include "../include/constante.h"
#include <iostream>

Joc_Arma_Conventionala::Joc_Arma_Conventionala(const std::string& nume1, const std::string& nume2,
                                               std::shared_ptr<Reguli_Arma> reguli_arma)
    : Joc(nume1, nume2, reguli_arma->get_cale_fisier()), reguli(std::move(reguli_arma)) {}

std::unique_ptr<Joc> Joc_Arma_Conventionala::clone() const {
    return std::make_unique<Joc_Arma_Conventionala>(p1.get_nume(), p2.get_nume(), reguli);
}

void Joc_Arma_Conventionala::start(){
    std::cout<<"\nÎncepe jocul de ARMĂ CONVENȚIONALĂ! Mult succes ambilor jucători!\n\n";
    reguli->afisare_reguli();
    suprafata.suprafata_noua();
    std::cout << suprafata;
    continua();
}

void Joc_Arma_Conventionala::proceseaza_actiuni_diferite(int actiune1, int actiune2){
    if ((actiune1 == atac && actiune2 == parada) ||
        (actiune1 == ocolire && actiune2 == atac) ||
        (actiune1 == parada && actiune2 == ocolire)) {
        std::cout<<p2.get_nume()<<" are prioritate și lovește!\n";
        afisare_tinta();
        std::cout<<p2.get_nume()<<": Alege punctul unde lovești (1-6): ";
        int punct_lovitura;
        std::cin>>punct_lovitura;

        if (reguli->validare_lovitura(punct_lovitura)){
            std::cout<<"Lovitura este valabilă! "<<p2.get_nume()<<" punctează!\n";
            p2.primeste_un_punct();
        }else{
            std::cout<<"Lovitura este invalidă! Jucătorii revin la pozițiile anterioare.\n";
            p1.revenire_pozitie_initiala(pozitie_initiala_p1);
            p2.revenire_pozitie_initiala(pozitie_initiala_p2);
        }
    }else{
        std::cout<<p1.get_nume()<<" are prioritate și lovește!\n";
        afisare_tinta();
        std::cout<<p1.get_nume()<<": Alege punctul unde lovești (1-6): ";
        int punct_lovitura;
        std::cin>>punct_lovitura;

        if(reguli->validare_lovitura(punct_lovitura)){
            std::cout<<"Lovitura este valabilă! "<<p1.get_nume()<<" punctează!\n";
            p1.primeste_un_punct();
        }else{
            std::cout<<"Lovitura este invalidă! Jucătorii revin la pozițiile anterioare.\n";
            p1.revenire_pozitie_initiala(pozitie_initiala_p1);
            p2.revenire_pozitie_initiala(pozitie_initiala_p2);
        }
    }

    suprafata.suprafata_noua();
}

bool Joc_Arma_Conventionala::validare_lovitura(int punct_lovitura){
    return reguli->validare_lovitura(punct_lovitura);
}

bool Joc_Arma_Conventionala::moment_al_jocului(){
    std::cout<<"Moment de luptă! Fiecare jucător să-și aleagă acțiunea.\n";
    std::cout<<p1.get_nume()<<": ";
    int actiune1=p1.alege_actiune();
    std::cout<<p2.get_nume()<<": ";
    int actiune2=p2.alege_actiune();

    statistici.inregistreaza_actiune(p1.get_nume(), actiune1, p1.pozitie_actuala(), p2.pozitie_actuala());
    statistici.inregistreaza_actiune(p2.get_nume(), actiune2, p2.pozitie_actuala(), p1.pozitie_actuala());

    if (actiune1==actiune2){
        proceseaza_actiuni_egale_comune();
    }else{
        proceseaza_actiuni_diferite(actiune1, actiune2);
    }

    return true;
}

void Joc_Arma_Conventionala::proceseaza_actiuni_egale(){
    std::cout<<"Ambii jucători au ales aceeași acțiune! Nu se acordă puncte.\n";
    p1.se_retrage_o_pozitie();
    p2.se_retrage_o_pozitie();
    suprafata.suprafata_noua();
    std::cout<<suprafata;
}
