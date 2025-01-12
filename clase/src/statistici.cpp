#include "../include/statistici.h"

void Statistici::inregistreaza_actiune(const std::string& nume_jucator, int actiune, int pozitie_curenta, int pozitie_adversar){
    JucatorStat& stat=statistici[nume_jucator];

    switch (actiune){
        case 1: stat.atacuri++; break;
        case 2: stat.ocoliri++; break;
        case 3: stat.parade++; break;
    }

    if (pozitie_curenta<pozitie_adversar){
        stat.avansari++;
    }else if(pozitie_curenta>pozitie_adversar){
        stat.retrageri++;
    }
}

std::string Statistici::determina_agresivitate(const JucatorStat& stat) const{
    if (stat.atacuri>=stat.parade && stat.atacuri>=stat.ocoliri){
        return "agresiv";
    }else if(stat.parade>=stat.atacuri && stat.parade>=stat.ocoliri){
        return "pragmatic";
    }else{
        return "anticipativ";
    }
}

std::string Statistici::determina_stil_joc(const JucatorStat& stat) const{
    if (stat.avansari>stat.retrageri){
        return "a preluat inițiativa";
    }else if(stat.retrageri>stat.avansari){
        return "s-a retras strategic";
    }else{
        return "echilibrat";
    }
}

void Statistici::afisare_statistici() const{
    std::cout << "\n=== Statistici Finale ===";
    std::cout<<"\n";

    for (const auto& [nume, stat]:statistici){
        int total_actiuni=stat.atacuri+stat.parade+stat.ocoliri;
        double procent_atacuri=total_actiuni>0 ? (stat.atacuri * 100.0 / total_actiuni) : 0.0;
        double procent_parade=total_actiuni>0 ? (stat.parade * 100.0 / total_actiuni) : 0.0;
        double procent_ocoliri=total_actiuni>0 ? (stat.ocoliri * 100.0 / total_actiuni) : 0.0;

        std::cout<<"Jucător: "<<nume << "\n"
                 <<"-Agresivitate/Pragmatism: " << determina_agresivitate(stat)<<"\n"
                 <<"-Stil de joc: " << determina_stil_joc(stat) << "\n"
                 <<"-Procentaj acțiuni alese:\n"
                 <<"   * Atacuri: "<<procent_atacuri<<"%\n"
                 <<"   * Parade: "<<procent_parade<<"%\n"
                 <<"   * Ocoliri: "<<procent_ocoliri<<"%\n"
                 <<"De cate ori a ales fiecare actiune: \n"
                 <<"-Atacuri:"<<stat.atacuri<<", Parade: "<<stat.parade<<", Ocoliri: "<<stat.ocoliri<<"\n"
                 <<"De cate ori a s-a indreptat spre adversar: \n"
                 <<"- Avansări: "<<stat.avansari<<", Retrageri: "<<stat.retrageri<<"\n\n";
    }
}

