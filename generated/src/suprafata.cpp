#include <iostream>
#include "suprafata.h"

Suprafata::Suprafata(Jucator& p1_dat, Jucator& p2_dat):
    p1(p1_dat), p2(p2_dat){}

void Suprafata::suprafata_noua(){
    int poz1=p1.pozitie_actuala();
    int poz2=p2.pozitie_actuala();
    std::array<int, 12> suprafata_noua={0};
    for(int i=0; i<12; i++){
        if(i==poz1){
            suprafata_noua[i]=1;
        }
        else if(i==poz2){
            suprafata_noua[i]=2;
        }
    }
    suprafata=suprafata_noua;
    
}

void Suprafata::afisare_suprafata_actuala(){
    std::cout<<"Pozitionarea Jucatorilor:\n";
    for(int i=0; i<12; i++){
        if(suprafata[i]==0){
            std::cout<<"[__]";
        }
        else if(suprafata[i]==1){
            std::cout<<"[ p1 ]";
        }
        else{
            std::cout<<"[ p2 ]";
        }
    }
    std::cout<<"\n\n";
}

void Suprafata::resetare_suprafata(){
    int poz1=4;
    int poz2=7;
    
    p1.revenire_pozitie_initiala(poz1);
    p2.revenire_pozitie_initiala(poz2);

    std::array<int, 12> suprafata_noua={0};
    suprafata_noua[poz1]=1;
    suprafata_noua[poz2]=2;

}

