#include <iostream>
#include <fstream>
#include "../include/joc.h"

const int Joc::scor_maxim=5;
const int Joc::pozitie_initiala_p1=4;
const int Joc::pozitie_initiala_p2=7;

Joc::Joc(const std::string& nume1, const std::string& nume2, const std::string& reguli_fisier,
         int pozitie1, int pozitie2, int puncte1, int puncte2)
    : p1(nume1, pozitie1, puncte1), 
      p2(nume2, pozitie2, puncte2),
      suprafata(p1, p2),
      reguli_fisier(reguli_fisier) {}

void Joc::start(){
    std::cout<<"\nIncepe jocul! Mult succes ambilor jucatori!\n\n";
    std::cout<<"===================================\n";
    suprafata.suprafata_noua();
    std::cout<<suprafata;
    continua();
}

void Joc::afiseaza_reguli(){
    std::ifstream fin(reguli_fisier);
    if (!fin) {
        std::cerr << "Eroare la deschiderea fișierului de reguli: " << reguli_fisier << "\n";
        return;
    }
    std::string linie;
    while (std::getline(fin, linie)) {
        std::cout << linie << "\n";
    }
    fin.close();
}

void Joc::continua(){
    while(true){
        if (!p1.verificare_pozitie_capat() && !p2.verificare_pozitie_capat()){
            std::cout << p1.get_nume()<<": ";
            p1.alegere_mutare();
            std::cout << p2.get_nume()<<": ";
            p2.alegere_mutare();

            suprafata.suprafata_noua();
            std::cout << suprafata;

            if (verificare_moment_lupta()){
                continuare_moment_lupta();
            }else{
                continua();
            }

        }else if(p1.verificare_pozitie_capat() && p2.verificare_pozitie_capat()){
            std::cout<<"Ambii jucatori vor avansa o pozitie automat, deoarece sunt la capatul plansei\n";
            p1.avanseaza_o_pozitie();
            p2.se_retrage_o_pozitie();
            suprafata.suprafata_noua();
            std::cout<<suprafata;
            continua();
        }else{
            jucator_la_capat();
        }

        if(verificare_meci_incheiat()){
            break;
        }
    }
}

void Joc::continuare_moment_lupta(){
    if (moment_al_jocului()){
        int puncte1=p1.scor_actual();
        int puncte2=p2.scor_actual();
        std::cout<<"Scorul este: " <<puncte1<<"-"<<puncte2<<"\n";

        if (verificare_meci_incheiat()){
            return;
        }
        suprafata.resetare_suprafata();
        suprafata.suprafata_noua();
        std::cout<<suprafata;
    }
    continua();
}

void Joc::jucator_la_capat(){
    if (p1.verificare_pozitie_capat()){
        std::cout<<"Jucatorul p1 va fi mutat automat o pozitie inainte, deoarece este la capat\n";
        p1.avanseaza_o_pozitie();
        std::cout<<p2.get_nume()<<": ";
        p2.alegere_mutare();
    }else if(p2.verificare_pozitie_capat()){
        std::cout<<"Jucatorul p2 va fi mutat automat o pozitie inapoi, deoarece este la capat\n";
        p2.se_retrage_o_pozitie();
        std::cout<<p1.get_nume()<<": ";
        p1.alegere_mutare();
    }
    suprafata.suprafata_noua();
    std::cout<<suprafata;

    if (verificare_moment_lupta()){
        continuare_moment_lupta();
    }else{
        continua();
    }
}

bool Joc::verificare_meci_incheiat(){
    if (p1.scor_actual()==5 && p2.scor_actual()!=5){
        std::cout<<"Felicitari! "<< p1.get_nume()<<" castiga Aurul!\n";
        return true;
    }else if(p2.scor_actual()==5 && p1.scor_actual()!=5){
        std::cout<<"Felicitari! "<< p2.get_nume()<<" castiga Aurul!\n";
        return true;
    }
    return false;
}

bool Joc::verificare_moment_lupta(){
    return abs(p1.pozitie_actuala()-p2.pozitie_actuala())==1;
}

void Joc::proceseaza_actiuni_egale_comune(){
    std::cout << "Ambii jucători au ales aceeași acțiune. Nu se acordă puncte și se revin la pozițiile anterioare.\n";
    int pozitie_anterioara_p1 = p1.pozitie_actuala() - 1;
    int pozitie_anterioara_p2 = p2.pozitie_actuala() + 1;
    p1.revenire_pozitie_initiala(pozitie_anterioara_p1);
    p2.revenire_pozitie_initiala(pozitie_anterioara_p2);

    suprafata.suprafata_noua();
    std::cout << suprafata;
}


void Joc::afisare_tinta(){    
        std::cout << "\n"
        << "                  _______                 \n"
        << "                 /       \\               \n"
        << "                |         |               \n"
        << "                |    x1   |               \n"
        << "                 \\__   __/              \n"
        << "          __________| |_________         \n"
        << "         |                      |        \n"
        << "        / /|                  |\\ \\     \n"
        << "  x2-->/ / |      x3          | \\ \\    \n"
        << "      / /  |                  |  \\ \\   \n"
        << "    _/ /_  |                  |  _\\ \\_ \n"
        << "   |     | |              x4  | |     |  \n"
        << "   |_____| |__________________| |_____|  \n"
        << "              |_|        |_|             \n"
        << "              |_|        |_|<--x5        \n"
        << "             /_/          \\_\\          \n"
        << "            |_|            |_|           \n"
        << "           _|_|            |_|_          \n"
        << "          |___|            |___|<--x6    \n";
}
