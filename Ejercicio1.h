#include <stdio.h>
#include <time.h>
#include <limits.h>


#ifndef EJERCICIO1_H
#define EJERCICIO1_H


typedef struct
{
    int tam_autobus;
    int edades[5];
    int numero_alumnos;
    int mejor;
    int mejor_comb[5];
    int comb_act[5];
    int nodos;
}DatosProblema;

void algoritmo_ejercicio1(int i,int ocupados,int primero,int ultimo,DatosProblema *datos);
void ejecutar_ejercicio1();

#endif
