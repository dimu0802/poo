#include <iostream>
#include <string>
#include "constante.h"
#include "joc.h"
#include "jucator.h"
#include "lupta.h"
#include "suprafata.h"



int main(){
    std::cout<<"\n\nFENCING DUEL-OLYMPIC GLORY\nFormat: Player vs Player\n\n";
    std::cout<<"\nDupa ce ti-ai dedicat o viata intreaga acestui sport, ai reusit sa ajungi in finala olimpica! Felicitari!\nAcum urmeaza cel mai important meci al tau, cel care te poate propulsa in istoria sportului tau. Crezi ca faci fata provocarii?";
    std::cout<<"\n\nMutari posibile: INAINTE: tasta 1; si INAPOI: tasta 2.\nIn momentul in care jucatorii ajung unul langa celalalt, urmeaza un moment de lupta.\nActiuni posibile: ATAC: tasta 1; OCOLIRE: tasta 2; PARADA: tasta 3\n";
    
    Joc joc("Jucator 1", "Jucator 2", 4, 7);
    joc.start();

    return 0;
}