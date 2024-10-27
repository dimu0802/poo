#ifndef JUCATOR_H
#define JUCATOR_H

#include <iostream>

class Jucator{
private:
    std::string nume;
    int pozitie;
    int numar_puncte;
public:
    explicit Jucator(const std::string& numedat, int pozitie_initiala, int numar_puncte_initial);
    Jucator(const Jucator& other);
    Jucator& operator=(const Jucator& other){
            if(this!=&other){
                nume=other.nume;
                pozitie=other.pozitie;
                numar_puncte=other.numar_puncte;
            }
            std::cout<<"s a apelat operatorul =\n";
            return *this;
        }
    void alegere_mutare();
    void avanseaza_o_pozitie();
    void se_retrage_o_pozitie();
    void actualizeaza_pozitie(int pozitie_dorita);
    int alege_actiune();
    void primeste_un_punct();
    int scor_actual();
    int pozitie_actuala();
    void revenire_pozitie_initiala(int pozitie_initiala);
    friend std::ostream& operator<<(std::ostream& os, const Jucator& player){
            os<<"Jucator: "<<player.nume<<", pozitie: "<<player.pozitie<<", numar de puncte: "<<player.numar_puncte<<"\n";
            return os;
        }
    bool verificare_pozitie_capat();
    ~Jucator();
};

#endif
