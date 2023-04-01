#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char **v ; // apunta a la direccion de memoria de un puntero simples
    int cantNombres;
    printf("Cantidad de nombres que ingresara: ");
    scanf("%d",&cantNombres);
    v = (char **)malloc(cantNombres * sizeof(char *));

    char *Buff; //variable auxiliar
    Buff= (char *) malloc(100*sizeof(char)); // asigno dinamicamente 

    fflush(stdin);

    for (int i = 0; i < cantNombres; i++)
    {
        printf("Ingrese el nombre %d: \n", i + 1);
        gets(Buff);
        v[i] = (char *)malloc(sizeof(char) * (strlen(Buff)+1)); //guardo espacio para 100 caracters, el 1 es para el \n??, strlen=longitud
        strcpy(v[i],Buff); // copi Buff en v[i]
    }
    
    free(Buff); // libero buff

    printf("Los nombres ingresados son: \n");
    for (int i = 0; i < cantNombres; i++)
    {
        puts(v[i]);
        free(v[i]); //libero la memoria de cada nombre
    }
    free(v); //libero v, que tiene el espacio reservado para los punteros simples


/* Otra forma de mostrar
    for (int i = 0; i < cantNombres; i++)
    {
        for (int j = 0; j < strlen(v[i]); j++)
        {
            printf("%c",v[i][j]);
        }
        printf("\n");
    }
*/

/* Los espacios no son contiguos, no se puede
for (int i = 0; i < cantNombres; i++)
    {
        for (int j = 0; j < strlen(v[i]); j++)
        {
            printf("%c",*(v + (i * strlen(v[i]) + j)));
        }
        printf("\n");
    }
*/
return 0;
}