#include <iostream>
#include <string>
#include "generated/include/joc.h"
#include "generated/include/jucator.h"
#include "generated/include/lupta.h"
#include "generated/include/suprafata.h"
#include "generated/include/scor.h"


int main(){
    Joc joc("Jucator 1", "Jucator 2", 4, 7);
    joc.start();

    return 0;
}