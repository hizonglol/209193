#include <iostream>

#include "stos.hh"


Stos::Stos() {

  last = 0;
  size = 8;

  tab = new int[size];

  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Stos::Stos(long _size) {

  last = 0;
  size = _size;

  tab = new int[size];

  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Stos::~Stos() {

  delete []tab;
}


void Stos::push(int _elem) {

  if(last == size) increase();

  tab[last] = _elem;
  ++last;
}


int Stos::pop() {

  int temp=decrease();
  --last;
  return temp;
}


void Stos::increase() {

  int *nowa = new int[size + 8];//tworzymy zastepczy stos o 8 wiekszy

  for(int i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;
  size += 8;//powiekszamy zmienna przechowujaca informacje o rozmiarze o 8
}


int Stos::decrease() {

  int temp = tab[size-1];//zmienna tymczasowa przechowujaca usuwany element
  --size;//pomniejszamy zmienna przechowujaca informacje o rozmiarze o 1
  int *nowa = new int[size];//tworzymy zastepczy stos o 1 mniejszy

  for(int i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;

  return temp;//zwracamy usuwany element
}


void Stos::mergesort(int poczatek, int koniec) {
  int *temptab = new int[size];
  int ip = poczatek;
  int ik = koniec;
  int is = (ip + ik + 1)/2;

  if (is-ip > 1) mergesort(ip, is-1);
  if (ik-is > 0) mergesort(is, ik);
  int i1 = ip;
  int i2 = is;

  for (int i=ip; i<=ik; ++i) {
    if ((i1==is) || ((i2<=ik) && (tab[i1] > tab[i2]))) {
      temptab[i] = tab[i2];
      ++i2;
    }
    else {
      temptab[i] = tab[i1];
      ++i1;
    }
  }

  for (int i=ip; i<=ik; ++i) tab[i] = temptab[i];
}
