#include "../include/joc_floreta.h"
#include <iostream>

Joc_Floreta::Joc_Floreta(const std::string& nume1, const std::string& nume2)
    : Joc(nume1, nume2, 4, 7){}

Joc_Floreta::Joc_Floreta(const Joc& joc)
    : Joc(joc.p1.get_nume(), joc.p2.get_nume(), joc.p1.pozitie_actuala(), joc.p2.pozitie_actuala()){}

void Joc_Floreta::start(){
    std::cout << "\nIncepe jocul de floreta! Mult succes ambilor jucatori!\n\n";
    suprafata.suprafata_noua();
    std::cout << suprafata;
    continua();
}

void Joc_Floreta::proceseaza_actiuni_egale(){
    std::cout<<"Ambii jucatori au ales aceeasi actiune. Nu se acorda puncte si se revin la pozitiile anterioare.\n";
    int pozitie_anterioara_p1=p1.pozitie_actuala()-1;
    int pozitie_anterioara_p2=p2.pozitie_actuala()+1;
    p1.revenire_pozitie_initiala(pozitie_anterioara_p1);
    p2.revenire_pozitie_initiala(pozitie_anterioara_p2);

    suprafata.suprafata_noua();
    std::cout<<suprafata;
}


void Joc_Floreta::proceseaza_actiuni_diferite(int actiune1, int actiune2){
    // int pozitie_p1_actuala = p1.pozitie_actuala();
    // int pozitie_p2_actuala = p2.pozitie_actuala();

    if((actiune1==atac && actiune2==parada) || (actiune1 == ocolire && actiune2 == atac) || (actiune1 == parada && actiune2 == ocolire)) {
        std::cout<<p2.get_nume()<<" are prioritate si loveste!\n";
        afisare_tinta();
        std::cout<<p2.get_nume()<<": Alege punctul unde lovesti (1-6): ";
        int punct_lovitura;
        std::cin>>punct_lovitura;

        if(validare_lovitura(punct_lovitura)) {
            std::cout << "Lovitura este valabila! "<< p2.get_nume()<<" puncteaza!\n";
            p2.primeste_un_punct();
        } else {
            std::cout << "Lovitura este invalida! Jucatorii revin la pozitiile anterioare.\n";
            p1.revenire_pozitie_initiala(pozitie_initiala_p1);
            p2.revenire_pozitie_initiala(pozitie_initiala_p2);
        }
    } else {
        std::cout<<p1.get_nume()<<" are prioritate si loveste!\n";
        afisare_tinta();
        std::cout<<p1.get_nume()<<": Alege punctul unde lovesti (1-6): ";
        int punct_lovitura;
        std::cin >> punct_lovitura;

        if (validare_lovitura(punct_lovitura)) {
            std::cout << "Lovitura este valabila! "<< p1.get_nume()<<" puncteaza!\n";
            p1.primeste_un_punct();
        }else{
            std::cout << "Lovitura este invalida! Jucatorii revin la pozitiile anterioare.\n";
            p1.revenire_pozitie_initiala(pozitie_initiala_p1);
            p2.revenire_pozitie_initiala(pozitie_initiala_p2);
        }
    }
    suprafata.suprafata_noua();
    std::cout << suprafata;
}


bool Joc_Floreta::validare_lovitura(int punct_lovitura){
    return (punct_lovitura==3 || punct_lovitura==4);
}

bool Joc_Floreta::moment_al_jocului(){
    std::cout<<"Va aflati intr-un moment de lupta! Fiecare jucator sa-si aleaga actiunea!\n";
    std::cout<<p1.get_nume()<<": ";
    int actiune1=p1.alege_actiune();
    std::cout<<p2.get_nume()<<": ";
    int actiune2=p2.alege_actiune();

    if (actiune1==actiune2){
        proceseaza_actiuni_egale();
    }else{
        proceseaza_actiuni_diferite(actiune1, actiune2);
    }

    return true;
}

