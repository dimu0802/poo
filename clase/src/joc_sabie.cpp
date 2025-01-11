#include "../include/joc_sabie.h"
#include "../include/constante.h"
#include <iostream>
#include <fstream>

Joc_Sabie::Joc_Sabie(const std::string& nume1, const std::string& nume2)
    : Joc(nume1, nume2, "reguli/sabie.txt", 4, 7) {}

std::unique_ptr<Joc> Joc_Sabie::clone()const{
    return std::make_unique<Joc_Sabie>(*this);
}

void Joc_Sabie::start(){
    std::cout<<"\nÎncepe jocul de SABIE! Mult succes ambilor jucători!\n\n";
    afiseaza_reguli();
    suprafata.suprafata_noua();
    std::cout << suprafata;
    continua();
}

void Joc_Sabie::proceseaza_actiuni_diferite(int actiune1, int actiune2){
    // int pozitie_p1_actuala = p1.pozitie_actuala();
    // int pozitie_p2_actuala = p2.pozitie_actuala();

    if ((actiune1==atac && actiune2==parada) ||
        (actiune1==ocolire && actiune2==atac) ||
        (actiune1==parada && actiune2==ocolire)){
        std::cout<<p2.get_nume()<<" are prioritate si loveste!\n";
        afisare_tinta();
        std::cout<<p2.get_nume()<<": Alege punctul unde lovesti (1-6): ";
        int punct_lovitura;
        std::cin>>punct_lovitura;

        if(validare_lovitura(punct_lovitura)){
            std::cout<<"Lovitura este valabila! "<< p2.get_nume()<<" puncteaza!\n";
            p2.primeste_un_punct();
        }else{
            std::cout<<"Lovitura este invalida! Jucatorii revin la pozitiile anterioare.\n";
            p1.revenire_pozitie_initiala(pozitie_initiala_p1);
            p2.revenire_pozitie_initiala(pozitie_initiala_p2);
        }
    }else{
        std::cout<<p1.get_nume()<<" are prioritate si loveste!\n";
        afisare_tinta();
        std::cout<<p1.get_nume()<<": Alege punctul unde lovesti (1-6): ";
        int punct_lovitura;
        std::cin>>punct_lovitura;

        if (validare_lovitura(punct_lovitura)) {
            std::cout<<"Lovitura este valabila! "<< p1.get_nume()<<" puncteaza!\n";
            p1.primeste_un_punct();
        }else{
            std::cout<<"Lovitura este invalida! Jucatorii revin la pozitiile anterioare.\n";
            p1.revenire_pozitie_initiala(pozitie_initiala_p1);
            p2.revenire_pozitie_initiala(pozitie_initiala_p2);
        }
    }

    suprafata.suprafata_noua();
}

bool Joc_Sabie::validare_lovitura(int punct_lovitura){
    return (punct_lovitura >= 1 && punct_lovitura <= 4);
}

void Joc_Sabie::proceseaza_actiuni_egale() {
    proceseaza_actiuni_egale_comune();
}

bool Joc_Sabie::moment_al_jocului(){
    std::cout<<"Moment de lupta in sabie! Fiecare jucator sa-si aleaga actiunea.\n";
    std::cout<<p1.get_nume()<<": ";
    int actiune1=p1.alege_actiune();
    std::cout<<p2.get_nume()<<": ";
    int actiune2=p2.alege_actiune();

    if (actiune1 == actiune2){
        proceseaza_actiuni_egale();
    }else{
        proceseaza_actiuni_diferite(actiune1, actiune2);
    }
    return true;
}