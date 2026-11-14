#include <stdio.h>
#include <stdlib.h>

void backtraking(int nivel,int *valor_letras[26],int *pos_ocupadas[10],const char letras_criptograma[],int *contador_nodos)
{
    contador_nodos++;
    char letra_actual=letras_criptograma[aux];

    if(aux==10)
    {
        if(ComprobarSuma()==true)//Tengo que implementar la funcion
        {
            //Guardar solucion
        }
        return;
    }

    for(int i=0;i<10;i++)
    {
        if(*pos_ocupadas[i]==1)
        {
            continue;
        }

        if((letra_actual=='H' || letra_actual=='P' || letra_actual=='T') && i==0)
        {
            continue;
        }

        valor_letras[letra_actual-'A']=cifra;

        pos_ocupadas[cifra]=1;

        backtraking(nivel++,&valor_letras,&pos_ocupadas,letras_criptograma,&contador_nodos);

        valor_letras[letra_actual-'A']=-1;

        pos_ocupadas[cifra]=0;


    }

}


int main()
{
    int Valor_letras[26];
    int pos_ocupadas[10]={0};
    const char letras_criptograma[]="HARYPOTELS";
    int aux=0,cont=0;

    backtraking(aux,&Valor_letras,&pos_ocupadas,letras_criptograma,&cont);


    return 0;
}
