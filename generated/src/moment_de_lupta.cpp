#include <iostream>
#include "lupta.h"

Lupta::Lupta(Jucator& p1_dat, Jucator& p2_dat, Suprafata& suprafata_data):
    p1(p1_dat), p2(p2_dat), suprafata(suprafata_data){}

int Lupta::moment_al_jocului(){
    std::cout<<"Va aflati intr-un moment de lupta! Fiecare jucator sa-si aleaga actiunea!\n";
    std::cout<<"Jucatorul p1: ";
    int actiune1=p1.alege_actiune();
    std::cout<<"Jucatorul p2: ";
    int actiune2=p2.alege_actiune();
    std::cout<<"\n";
    if(actiune1==actiune2){
        if(actiune1==0||actiune1==1){
            std::cout<<"Ambii jucatori au punctat!";
            p1.primeste_un_punct();
            p2.primeste_un_punct();
            suprafata.suprafata_noua();
        }else{
            std::cout<<"Ambii jucatori au parat. Fiecare se retrage un pas.";
            p1.se_retrage_o_pozitie();
            p2.avanseaza_o_pozitie();
        }
    }else if(actiune1==0 && actiune2==2){
        std::cout<<"A punctat Jucatorul 2!";
        p2.primeste_un_punct();
        suprafata.suprafata_noua();
    }
    else if(actiune2==0 && actiune1==2){
        std::cout<<"A punctat Jucatorul 1!";
        p1.primeste_un_punct(); 
        suprafata.suprafata_noua();}
    else if(actiune1==0 && actiune2==1){
        std::cout<<"A punctat Jucatorul 1!";
        p1.primeste_un_punct(); 
        suprafata.suprafata_noua();}
    else if(actiune2==0 && actiune1==1){
        std::cout<<"A punctat Jucatorul 2!";
        p2.primeste_un_punct(); 
        suprafata.suprafata_noua();}
    else if(actiune1==1 && actiune2==2){
        std::cout<<"A punctat Jucatorul 1!";
        p1.primeste_un_punct(); 
        suprafata.suprafata_noua();}
    else if(actiune2==1 && actiune1==2){
        std::cout<<"A punctat Jucatorul 2!";
        p2.primeste_un_punct(); 
        suprafata.suprafata_noua();}
    int verificare=0;
    if(actiune1==2 && actiune2==2){
        verificare=1;
    }
    std::cout<<"\n";
    return verificare;
}