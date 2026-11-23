#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifndef EJERCICIO2_H
#define EJERCICIO2_H

int ConvertirPalabra(const char palabra[],int valor_letras[26]);
bool ComprobarSuma(int valor_letras[26]);
int backtraking(int nivel,int valor_letras[26],int pos_ocupadas[10],const char letras_criptograma[],int *contador_nodos);
void ejecutar_ejercicio2();

#endif
