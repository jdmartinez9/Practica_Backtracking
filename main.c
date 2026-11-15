#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



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
        if(ComprobarSuma(valor_letras)==true)//Tengo que implementar la funcion
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


int main()
{
    int Valor_letras[26];
    int pos_ocupadas[10]={0};
    const char letras_criptograma[]="HARYPOTELS";
    int aux=0,cont=0,resultado;

    for(int i=0;i<26;i++)
    {
        Valor_letras[i]=-1;
    }

    resultado=backtraking(aux,Valor_letras,pos_ocupadas,letras_criptograma,&cont);

    if(resultado==0)
    {
        for (int i=0;i<26;i++)
        {
            if(Valor_letras[i]!=-1)
            {
                printf("%c:%d \n",'A'+ i,Valor_letras[i]);
            }
        }
    }
    else if(resultado==1)
    {
        printf("No se ha encontrado una solucion");
    }


    return 0;
}
