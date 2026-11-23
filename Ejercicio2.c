#include "Ejercicio2.h"


int ConvertirPalabra(const char palabra[],int valor_letras[26])
{
    int cifra=0;

    for (int i=0;i< strlen(palabra);i++)
    {
        cifra=cifra *10 + valor_letras[palabra[i]-'A'];
    }

    return cifra;
}

bool ComprobarSuma(int valor_letras[26])
{
    int palabra1,palabra2,palabra3,resultado;
    palabra1=ConvertirPalabra("HARRY",valor_letras);
    palabra2=ConvertirPalabra("POTTER",valor_letras);
    palabra3=ConvertirPalabra("TROLLS",valor_letras);

    resultado=palabra1+palabra2;

    if(resultado==palabra3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int backtraking(int nivel,int valor_letras[26],int pos_ocupadas[10],const char letras_criptograma[],int *contador_nodos)
{
    int resultado=0;
    (*contador_nodos)++;
    char letra_actual=letras_criptograma[nivel];

    if(nivel==10)
    {
        if(ComprobarSuma(valor_letras)==true)
        {
            printf("Solucion encontrada \n");
            return 0;
        }
        return 1;
    }

    for(int i=0;i<10;i++)
    {
        if(pos_ocupadas[i]==1)
        {
            continue;
        }

        if((letra_actual=='H' || letra_actual=='P' || letra_actual=='T') && i==0)
        {
            continue;
        }

        valor_letras[letra_actual-'A']=i;

        pos_ocupadas[i]=1;

        resultado=backtraking(nivel+1,valor_letras,pos_ocupadas,letras_criptograma,contador_nodos);

        if(resultado==0)
        {
            return 0;
        }

        valor_letras[letra_actual-'A']=-1;

        pos_ocupadas[i]=0;
    }
    return 1;
}



void ejecutar_ejercicio2()
{
    int Valor_letras[26];
    int pos_ocupadas[10]={0};
    const char letras_criptograma[]="HARYPOTELS";
    int aux=0,cont=0,resultado;

    // Variables de tiempo apartado E
    clock_t inicio, fin;
    double tiempo_usado;

    // Descifrar matricula
    const char matricula[] = "6531484901984";

    for(int i=0;i<26;i++)
    {
        Valor_letras[i]=-1;
    }

    // Inicio medicion apartado E
    inicio = clock();

    resultado=backtraking(aux,Valor_letras,pos_ocupadas,letras_criptograma,&cont);

    // Fin medicion apartado E
    fin = clock();
    tiempo_usado = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    if(resultado==0)
    {
        for (int i=0;i<26;i++)
        {
            if(Valor_letras[i]!=-1)
            {
                printf("%c:%d \n",'A'+ i,Valor_letras[i]);
            }
        }

        // Descifrar matricula
        printf("\n--- MATRICULA DESCIFRADA ---\n");
        printf("Matricula codificada: %s\n", matricula);
        printf("Mensaje oculto:       ");
        for(int i = 0; i < strlen(matricula); i++) {
            int digito = matricula[i] - '0';
            for(int j = 0; j < 26; j++) {
                if(Valor_letras[j] == digito) {
                    printf("%c", 'A' + j);
                    break;
                }
            }
        }
        printf("\n");

        // Imprimir resultados D y E
        printf("\n--- RENDIMIENTO ---\n");
        printf("Nodos explorados (Apartado D): %d\n", cont);
        printf("Tiempo empleado (Apartado E): %f segundos\n", tiempo_usado);
    }
    else if(resultado==1)
    {
        printf("No se ha encontrado una solucion");
    }
}
