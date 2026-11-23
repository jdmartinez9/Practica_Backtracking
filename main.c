#include <stdio.h>
#include "Ejercicio1.h"
#include "Ejercicio2.h"

int main()
{
    int opcion;

    printf("====PRACTICA BACKTRAKING====\n");
    printf("1.Ejercicio 1 -Autobus escolar\n");
    printf("2.Ejercicio 2 -Criptograma\n");
    printf("Seleccione una opcion");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        ejecutar_ejercicio1();
    break;
    case 2:
        ejecutar_ejercicio2();
    break;
    default:
        printf("Opcion no valida");
    break;

    }
    return 0;

}
