#include "../include/joc_spada.h"
#include <iostream>

Joc_Spada::Joc_Spada(const std::string& nume1, const std::string& nume2)
    : Joc(nume1, nume2, 4, 7){}

Joc_Spada::Joc_Spada(const Joc& joc)
    : Joc(joc.p1.get_nume(), joc.p2.get_nume(), joc.p1.pozitie_actuala(), joc.p2.pozitie_actuala()){}

void Joc_Spada::proceseaza_actiuni_egale(int actiune){
    if(p1.scor_actual()==4 && p2.scor_actual()==4){
        std::cout<<"Egalitate la 4-4! Se aplica regula speciala pentru spada.\n";
        if(actiune== atac||actiune==ocolire){
            std::cout<<"Lovitura dubla! Se scade un punct de la fiecare jucator.\n";
        }else{
            std::cout << "Ambii jucatori au parat! Faza se repeta.\n";
        }
    }else{
        if(actiune==atac||actiune==ocolire){
            std::cout<<"Ambii jucatori au punctat!\n";
            p1.primeste_un_punct();
            p2.primeste_un_punct();
        }else{
            std::cout<<"Ambii jucatori au parat! Fiecare se retrage o pozitie.\n";
            p1.se_retrage_o_pozitie();
            p2.se_retrage_o_pozitie();
        }
    }
    suprafata.suprafata_noua();
}


void Joc_Spada::proceseaza_actiuni_diferite(int actiune1, int actiune2){
    if ((actiune1==atac && actiune2==parada) || 
        (actiune1==ocolire && actiune2==atac) || 
        (actiune1==parada && actiune2==ocolire)) {
        std::cout<<p2.get_nume()<<" are prioritate si puncteaza!\n";
        p2.primeste_un_punct();
    } else {
        std::cout<<p1.get_nume()<< " are prioritate si puncteaza!\n";
        p1.primeste_un_punct();
    }
    suprafata.suprafata_noua();
}

bool Joc_Spada::validare_lovitura(int punct_lovitura){
    return (punct_lovitura>=1 && punct_lovitura<=6);
}

bool Joc_Spada::moment_al_jocului(){
    std::cout << "Moment de lupta in spada! Fiecare jucator sa-si aleaga actiunea.\n";
    std::cout<<p1.get_nume()<<": ";
    int actiune1=p1.alege_actiune();
    std::cout<<p2.get_nume()<<": ";
    int actiune2=p2.alege_actiune();

    if(actiune1==actiune2){
        proceseaza_actiuni_egale(actiune1);
    }else{
        proceseaza_actiuni_diferite(actiune1, actiune2);
    }
    return true;
}


