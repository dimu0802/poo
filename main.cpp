#include <iostream>
#include <string>
#include "constante.h"
#include "joc.h"
#include "jucator.h"
#include "lupta.h"
#include "suprafata.h"



int main(){
    std::cout<<"\n\nDupa ce ti-ai dedicat o viata intreaga acestui sport, ai reusit sa ajungi in finala olimpica! Felicitari!\nAcum urmeaza cel mai important meci al tau, cel care te poate propulsa in istoria sportului tau. Crezi ca faci fata provocarii?";
    Joc joc("Jucator 1", "Jucator 2", 4, 7);
    joc.start();

    return 0;
}