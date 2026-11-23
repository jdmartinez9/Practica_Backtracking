#include "Ejercicio1.h"


void algoritmo_ejercicio1(int i,int ocupados,int primero,int ultimo,DatosProblema *datos)
{
    datos->nodos++;
    if (ocupados==datos->tam_autobus){
        int candidato= datos->edades[ultimo]-datos->edades[primero];
        if (candidato<datos->mejor){
            datos->mejor=candidato;
            for (int j = 0; j < datos->numero_alumnos; j++){
               datos->mejor_comb[j] = (j < i) ? datos->comb_act[j] : 0;
            }
        }
        return;
    }
    if (datos->numero_alumnos==i){
        return;
    }

    if(ocupados>0 && datos->edades[i]-datos->edades[primero]>=datos->mejor){
        return;
    }
    /*Primera iteracion*/
    datos->comb_act[i]=1;
    if (ocupados==0){
        algoritmo_ejercicio1(i+1,ocupados+1,i,i,datos);

    }else{
    /*Siguientes iteraciones*/
        algoritmo_ejercicio1(i+1,ocupados+1,primero,i,datos);
    }
    datos->comb_act[i]=0;
    if (datos->numero_alumnos - i - 1 >= datos->tam_autobus - ocupados){
       algoritmo_ejercicio1(i + 1, ocupados, primero, ultimo,datos);
    }


}

void ejecutar_ejercicio1()
{
     DatosProblema datos={
        .tam_autobus=3,
        .edades = {7,8,9,12,13},
        .numero_alumnos=5,
        .mejor=INT_MAX,
        .mejor_comb={0},
        .comb_act={0},
        .nodos=0
    };

    double tiempo;


    clock_t inicio = clock();
    algoritmo_ejercicio1(0,0,0,0,&datos);
    clock_t fin = clock();
    tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Diferencia edades: %d",datos.mejor);
    printf("\nMejor Combinacion: ");
    for (int j = 0; j < datos.numero_alumnos; j++){
        if (datos.mejor_comb[j] == 1){
           printf("%d ", datos.edades[j]);
        }

    }
    printf("\nNodos explorados: %d",datos.nodos);
    printf("\nTiempo backtraking: %f s",tiempo);
}
