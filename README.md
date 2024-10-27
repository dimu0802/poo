# Fencing Duel-Olympic Glory

Dupa ce ti-ai dedicat o viata intreaga acestui sport, ai reusit sa ajungi in finala olimpica! Felicitari! Acum urmeaza cel mai important meci al tau, cel care te poate propulsa in istoria sportului tau. Crezi ca faci fata provocarii? 

 

REGULI 

INTRODUCERE: 

Pentru simplitatea explicatiei, vom defini urmatorul set de reguli: 

Scopul jocului este acela de a ajunge la 5 puncte(scoruri castigatoare: 5-0, 5-3, 5-4 etc.). 

Scrima este un sport individual jucat intre doi adversari directi, deci meciul va fi intre P1 si P2. Suprafata de lupta (numita in termeni de specialitate plansa de scrima) va avea 12 spatii. Pentru o imagine mai buna, sa definim suprafata de joc ca un vector suprafata[12]. 

              

Suprafata[12]: 

[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ][ 8 ][ 9 ][10 ][11 ] 

 

START MECI: 

Orice meci de scrima incepe de la mijlocul plansei, adversarii aflandu se la doua bucati distanta. Deci, P1 va fi pozitionat pe suprafata[4], iar P2 pe suprafata[7]. 

[   ][   ][   ][   ][ P1 ][   ][   ][ P2 ][   ][   ][   ][   ]   

In mod arbitrat, vom alege ca cel care incepe sa fie P1 (dupa ce unul dintre adversari puncteaza si se revine la pozitia initiala, va fi randul lui P2 sa inceapa si tot asa).  

Definim momentul in care cei doi adversari se afla unul in fata celuilalt ca fiind MOMENT DE LUPTA. In aceasta situatie se poate ajunge folosind mutarile de deplasare: PAS_INAINTE si PAS_INAPOI. Din pozitia de start, daca P1 ar folosi comanda PAS_INAINTE acesta ar ajunge de pe suprafata[4] pe suprafata[5]. Dupa mutarea lui P1 este randul lui P2 sa aleaga directia in care va avansa cu o casuta. 

 

 

 

MOMENT DE LUPTA: 

[  ][   ][   ][   ][   ][   ][   ][   ][   ][ P1][ P2 ][   ] 

Sa presupunem ca P1 este cel care a avansat ultimul si a generat un MOMENT DE LUPTA. Astfel, el este cel al carui rand va fi, deoarece scrima este un sport de lupta si cel care initiaza actiunea are prioritate.  

 

ACTIUNI si PUNCTARE 

In continuare, definim cele trei ACTIUNI din MOMENTUL DE LUPTA: 

ATAC – lovitura rapida 

OCOLIRE DE PARADA – atac inselator 

PARADA – apara care poate fi dejucata 

Fiecare jucator isi va alege in acest moment in acest moment. In functie de ce alege fiecare, vor fi 6 situatiii separate. 

Le explicam:  

-Daca atat P1 cat si P2 aleg ATAC, ambii vor puncta si vor primi cate un punct. Se revine la pozitia initiala. 

-Daca atat P1 cat si P2 aleg PARADA, cei doi vor face cate un pas inapoi, deoarece nu au aratat intentia de a ataca. 

-Daca atat P1 cat si P2 aleg OCOLIRE DE PARADA, ambii vor puncta si vor primi cate un punct. Se revine la pozitia initiala. 

-Daca P1 alege ATAC si P2 alege PARADA, P2 castiga un punct, deoarece a ghicit intentia lui P1 de a ataca. Se revina la pozitia initiala. 

-Daca P1 alege ATAC si P2 alege OCOLIRE DE PARADA, P1 castiga un punct deoarece atacul este mai rapid decat ocolirea de parada. Se revine la pozitia initiala. 

-Daca P1 alege PARADA si P2 alege OCOLIRE DE PARADA, P2 castiga un punct deoarece a ghicit decizia lui P1 de a se apara. Se revine la pozitia initiala. 

 

FINAL 

Asa se puncteaza. Cel care ajunge primul la 5 castiga. Exista situatia speciala in care unul dintre jucatori ajunge la capatul suprafetei (P1 la suprafata[0] sau P2 la suprafata[11]). In aceasta situatie, cel care este la capat nu mai avea varianta de PARADA, deoarece aceasta presupune un pas inapoi, pentru care nu mai e loc. 

Asta e tot. Intuitia sa fie cu tine. Asteptam AURUL!


## Tema 1

#### Cerințe
- [x] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [x] constructori de inițializare cu parametri
- [x] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.


2. Pasul de compilare
```sh
cmake --build build --config Debug --parallel 6
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.

3. Pasul de instalare (opțional)
```sh
cmake --install build --config Debug --prefix install_dir
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
