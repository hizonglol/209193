#include <iostream>

#include "stos.hh"
#include "benchmark.hh"
#include "algorithm_stos.hh"


/* Funkcja wykonujaca algorytm wczytywania elementow do stosu */
void AlgorithmStos::runAlgorithm(int _border) {

  for(int i=0; i<_border; ++i)
    stos.push(tab[i]);
}


/* Sortowanie przez scalanie */
void AlgorithmStos::sort(int _border) {

  stos.mergesort(0, _border-1);
}
