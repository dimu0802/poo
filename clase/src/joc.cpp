#include <iostream>
#include "../include/joc.h"

Joc::Joc(const std::string& nume1, const std::string& nume2, int pozitie1, int pozitie2, int puncte1, int puncte2)
    : p1(nume1, pozitie1, puncte1), p2(nume2, pozitie2, puncte2),
       suprafata(p1, p2), moment(p1, p2, suprafata) {}

void Joc::start(){
    std::cout<<"\n";
    std::cout<<"Incepe jocul! Mult succes ambilor jucatori!\n\n";
    std::cout<<"*********************************************************\n";
    suprafata.suprafata_noua();
    std::cout<<suprafata;
    continua();  
}
void Joc::continua(){
    if(!p1.verificare_pozitie_capat() && !p2.verificare_pozitie_capat()){
        std::cout<<"Jucatorul p1: ";
        p1.alegere_mutare();
        std::cout<<"Jucatorul p2: ";
        p2.alegere_mutare();
        suprafata.suprafata_noua();
        std::cout<<suprafata;
        continuare_moment_lupta();
        continuare_meci_incheiat();
    }else if(p1.verificare_pozitie_capat() && p2.verificare_pozitie_capat()){
        std::cout<<"Ambii jucatori vor avansa o pozitie automat, deoarece sunt la capatul plansei\n";
        p1.avanseaza_o_pozitie();
        p2.se_retrage_o_pozitie();
        suprafata.suprafata_noua();
        std::cout<<suprafata;
    }else if(p1.verificare_pozitie_capat() || p2.verificare_pozitie_capat()){
        jucator_la_capat();
    }
}

void Joc::jucator_la_capat(){
    if(p1.verificare_pozitie_capat()){
        std::cout<<"Jucatorul p1 va fi mutat automat o pozitie inainte, deoarece este la capat\n";
        p1.avanseaza_o_pozitie();
        std::cout<<"Jucatorul p2: ";
        p2.alegere_mutare();
    }else if(p2.verificare_pozitie_capat()){
        std::cout<<"Jucatorul p2 va fi mutat automat o pozitie inapoi, deoarece este la capat\n";
        p2.avanseaza_o_pozitie();
        std::cout<<"Jucatorul p1: ";
        p1.alegere_mutare();
    }
    suprafata.suprafata_noua();
    std::cout<<suprafata;
    continuare_moment_lupta();   
    continuare_meci_incheiat();
}


void Joc::continuare_moment_lupta(){
    if(verificare_moment_lupta()){
            if(moment.moment_al_jocului()){
                int puncte1=p1.scor_actual();
                int puncte2=p2.scor_actual();
                std::cout<<"Scorul este: "<<puncte1<<"-"<<puncte2<<"\n";
                suprafata.resetare_suprafata();
                suprafata.suprafata_noua();
                operator<<(std::cout, suprafata);
            }else{
                continua();
            }
    }else continua();
}

void Joc::continuare_meci_incheiat(){
    if(verificare_meci_incheiat()){}
    else if(verificare_egalitate4()){
        egalitate4();
        continua();
    }else continua();
}

bool Joc:: verificare_moment_lupta(){
    int poz1=p1.pozitie_actuala();
    int poz2=p2.pozitie_actuala();
    if(poz2-poz1==1){
        return true;
    }else return false;
}

bool Joc::verificare_meci_incheiat(){
    int puncte1=p1.scor_actual();
    int puncte2=p2.scor_actual();
    if((puncte1==5 && puncte2!=5) || (puncte2==5 && puncte1!=5)){
        if(puncte1==5){
        std::cout<<"Felicitari! Jucatorul 1 castiga Aurul!\n";
        }else{
            std::cout<<"Felicitari! Jucatorul 2 castiga Aurul!\n";
        }
        return true;
    }else return false;
}

bool Joc::verificare_egalitate4(){
    int puncte1=p1.scor_actual();
    int puncte2=p2.scor_actual();
    if(puncte1==5 && puncte2==5){
        return true;
    }else return false;
}

void Joc::egalitate4(){
    int puncte1=p1.scor_actual();
    int puncte2=p2.scor_actual();
    if(puncte1==5 && puncte2==5){
        std::cout<<"Scorul este 5-5. Se scoate cate o tusa de la fiecare jucator. \nVom juca pana cand unul dintre jucatori puncteaza o lovitura simpla.\nScorul este 4-4\n\n";
    }
    p1.scade_un_punct();
    p2.scade_un_punct();
    suprafata.suprafata_noua();
    operator<<(std::cout, suprafata);
}


