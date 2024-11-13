#include <iostream>
#include <string>
#include "constante.h"
#include "joc.h"
#include "jucator.h"
#include "lupta.h"
#include "suprafata.h"



int main(){
    std::cout<<"\n\n===================================\n"
             <<"FENCING DUEL-OLYMPIC GLORY\n"
             <<"Format: Player vs Player\n"
             <<"===================================\n\n"
             <<"\nDupa ce ti-ai dedicat o viata intreaga\n"
             <<"acestui sport, ai reusit sa ajungi in finala olimpica! Felicitari!\n"
             <<"Acum urmeaza cel mai important meci al tau, cel care te poate propulsa\n"
             <<"in istoria sportului tau. Crezi ca faci fata provocarii?\n\n"
             <<"===================================\n"
             <<"\nREGULI:"
             <<"\nMutari posibile: INAINTE: tasta 1; si INAPOI: tasta 2.\n"
             <<"In momentul in care jucatorii ajung unul langa celalalt, urmeaza un moment de lupta.\n"
             <<"Actiuni posibile: ATAC: tasta 1; OCOLIRE: tasta 2; PARADA: tasta 3\n\n"
             <<"Situatii posibile:\n"
             <<"1) ATAC-ATAC: puncteaza ambii"
             <<"2) OCOLIRE-OCOLIRE: puncteaza ambii"
             <<"3) PARADA-PARADA: ambii se retrag"
             <<"4) ATAC-PARADA: puncteaza PARADA"
             <<"5) ATAC-OCOLIRE: puncteaza ATAC"
             <<"6) OCOLIRE-PARADA: puncteaza OCOLIRE"
             <<"===================================\n";
    Joc joc("Jucator 1", "Jucator 2", 4, 7);
    joc.start();

    return 0;
}