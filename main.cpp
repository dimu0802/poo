#include <iostream>
#include <string>
#include "joc.h"
#include "jucator.h"
#include "lupta.h"
#include "suprafata.h"
#include "scor.h"


int main(){
    Joc joc("Jucator 1", "Jucator 2", 4, 7);
    joc.start();

    return 0;
}