#include "../include/joc_spada.h"
#include "../include/constante.h"
#include <iostream>
#include <fstream>

Joc_Spada::Joc_Spada(const std::string& nume1, const std::string& nume2)
    : Joc(nume1, nume2, "reguli/spada.txt", 4, 7){}

std::unique_ptr<Joc> Joc_Spada::clone() const{
    return std::make_unique<Joc_Spada>(*this);
}

void Joc_Spada::start(){
    std::cout<<"\nÎncepe jocul de SPADĂ! Mult succes ambilor jucători!\n\n";
    afiseaza_reguli();
    suprafata.suprafata_noua();
    std::cout<<suprafata;
    continua();
}

void Joc_Spada::proceseaza_actiuni_egale(){
    std::cout<<"Ambii jucători au ales aceeași acțiune! Unul dintre jucatori sa mai introduca acțiunea (1 - atac, 2 - ocolire, 3 - paradă):\n";
    int actiune;
    std::cin>>actiune;

    if (actiune < 1 || actiune > 3) {
        std::cout << "Acțiune invalidă! Reintrodu acțiunea corectă.\n";
        return proceseaza_actiuni_egale();
    }

    proceseaza_actiuni_egale_spada(actiune);
}

void Joc_Spada::proceseaza_actiuni_egale_spada(int actiune){
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
        proceseaza_actiuni_egale();
    }else{
        proceseaza_actiuni_diferite(actiune1, actiune2);
    }
    return true;
}


