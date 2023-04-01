#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *v[5] ; // vector de punteros, guarda la direccion de memoria de 5 cadenas

    char *Buff; //variable auxiliar
    Buff= (char *) malloc(100*sizeof(char)); // asigno dinamicamente 

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: \n", i + 1);
        gets(Buff);
        *(v + i) = (char *)malloc(sizeof(char) * (strlen(Buff)+1)); //guardo espacio para 100 caracters, el 1 es para el \n??, strlen=longitud
        strcpy(v[i],Buff); // copi Buff en v[i]
    }

    printf("Los nombres ingresados son: \n");
    for (int i = 0; i < 5; i++)
    {
        puts(v[i]);
        free(v[i]); //libero la memoria
    }
    free(Buff);
return 0;
}


/*
for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: \n", i + 1);
        v[i] = (char *)malloc(sizeof(char) * 100); //guardo espacio para 100 caracters
        gets(v[i]);
    }


    printf("Los nombres ingresados son: \n");
    for (int i = 0; i < 5; i++)
    {
        puts(v[i]);
        free(v[i]); //libero la memoria
    }
*/