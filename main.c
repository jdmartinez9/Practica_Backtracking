#include <stdio.h>
#include <stdlib.h>

int tam_autobus=3;
int edades[] = {7,8,9,12,13};
int numero_alumnos=5;
int mejor=5;
int mejor_comb[5];
int comb_act[5];

void algoritmo_ejercicio1(int i,int ocupados,int primero,int ultimo){
    if (ocupados==tam_autobus){
        int candidato= edades[ultimo]-edades[primero];
        if (candidato<mejor){
            mejor=candidato;
            for (int j = 0; j < numero_alumnos; j++){
               mejor_comb[j] = (j < i) ? comb_act[j] : 0;
            }
        }
        return;
    }
    if (numero_alumnos==i){
        return;
    }

    if(ocupados>0 && edades[i]-edades[primero]>=mejor){
        return;
    }
    /*Primera iteracion*/
    comb_act[i]=1;
    if (ocupados==0){
        algoritmo_ejercicio1(i+1,ocupados+1,i,i);

    }else{
    /*Siguientes iteraciones*/
        algoritmo_ejercicio1(i+1,ocupados+1,primero,i);
    }
    comb_act[i]=0;
    if (numero_alumnos - i - 1 >= tam_autobus - ocupados){
       algoritmo_ejercicio1(i + 1, ocupados, primero, ultimo);
    }


}

int main()
{
    algoritmo_ejercicio1(0,0,0,0);
    printf("Diferencia edades: %d",mejor);
    printf("\nMejor Combinacion: ");
    for (int j = 0; j < numero_alumnos; j++){
        if (mejor_comb[j] == 1){
           printf("%d ", edades[j]);
        }

    }

}
