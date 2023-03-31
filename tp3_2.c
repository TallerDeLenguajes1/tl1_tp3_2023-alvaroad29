#include <stdio.h>
#include <stdlib.h> //permite usar la funcion rand()
#include <time.h> // permite usar la funcion time()

#define N 5
#define M 12
/*
    2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
    generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
    es un mes. Ud. debe realizar las siguientes tareas:
    a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
    b. Muestre por pantalla los valores cargados
    c. Saque el promedio de ganancia por año y muestrelos por pantalla
    d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
    cuándo ocurrió.

*/

/*------------------------------FUNCIONES-------------------------------*/
void promedioPorAnio(int matriz[N][M]);
void cargar(int matriz[N][M]); //xq *matriz no funciona?? a[2] int a[] int *a 
void mostrar(int matriz[N][M]);
void maxMin(int matriz[N][M]);


int main()
{
    srand(time(NULL)); // srand me genera una semilla a partir de time

    int matriz[N][M];
    cargar(matriz);
    mostrar(matriz);
    promedioPorAnio(matriz);
    maxMin(matriz);

    return 0;
}


//Funcion cargar


void cargar(int matriz[N][M]){ // si funciona xq mando las constantes N y M??????
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matriz[i][j] = 10000 + rand() % 40001; // limiteInferior + rand() % (limireSuperior - limiteInferior + 1)
        }
        
    }
    
}

/*
void cargar(int matriz[N][M]){ //No funciona
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(matriz  + (i * M  + j)) = 10000 + rand() % 40001; 
        }
        
    }
    
}
*/


// Funcion mostrar
void mostrar(int matriz[N][M]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d  ",matriz[i][j]);
        }
        printf("\n");
    }
    
}

//
void promedioPorAnio(int matriz[N][M]){
    float suma;
    for (int i = 0; i < N; i++)
    {
        suma = 0;
        for (int j = 0; j < M; j++)
        {
            suma = suma + matriz[i][j];
        }
        printf("\n");
        printf("El promedio de ganancia del a%co %d es : %.2f",164,i+1,suma/12);
    }
}

void maxMin(int matriz[N][M]){
    int filaMin,columnaMin,filaMax,columnaMax;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 && j == 0)
            {
                filaMin = i;
                columnaMin = j;
                filaMax = i;
                columnaMax = j;
            }else
            {
                if (matriz[i][j] > matriz[filaMax][columnaMax])
                {
                    filaMax = i;
                    columnaMax = j;
                }
                if (matriz[i][j] < matriz[filaMin][columnaMin])
                {
                    filaMin = i;
                    columnaMin = j;
                }
            }
        }
    }
    printf("\nEl valor minimo obtenido es : %d correspondiente al a%co %d y mes %d\n",matriz[filaMin][columnaMin],164,filaMin+1,columnaMin+1);
    printf("\nEl valor maximo obtenido es : %d correspondiente al a%co %d y mes %d\n",matriz[filaMax][columnaMax],164,filaMax+1,columnaMax+1);
}
