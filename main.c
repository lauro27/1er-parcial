#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"
#include "pelicula.h"


#define TRUE 1
#define FALSE 0
#define TAM 10
#define TAMPELI 10

void menuMostrar(ePelicula[], eActor[]);



int main()
{
    int idC = 1000;
    ePelicula listaPelicula[TAMPELI];
    eActor listaActor[TAM];

    int i;
    for(i = 0; i<TAMPELI; i++)
    {
        listaPelicula[i].estado = 0;
    }
    inicializarPelicula(listaPelicula, listaActor, TAMPELI, TAM);
    inicializarActor(listaActor);
    int end = FALSE;
    int opcion;
    do{
        printf("1 - ALTA\n2 - MODIFICAR\n3 - BAJA\n4 - MOSTRAR\n5 - SALIR\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                insertarPelicula(listaPelicula, listaActor, TAMPELI, idC);
                break;
            case 2:
                editarPelicula(listaPelicula, listaActor, TAMPELI, TAM);
                break;
            case 3:
                borrarPelicula(listaPelicula, TAMPELI);
                break;
            case 4:
                menuMostrar(listaPelicula, listaActor);
                break;
            case 5:
                end = TRUE;
                break;
            }
    }while(end == FALSE);
    return 0;
}

void menuMostrar(ePelicula p[], eActor a[])
{
    int op;
    printf("1 - Mostrar peliculas con actor principal\n2 - Mostrar peliculas sin actor principal\n3 - Mostrar peliculas ordenadas por a�o de estreno\n4 - Mostrar actores ordenados por pa�s\n5 - Mostrar Todo\n6 - Mostrar Actores de EEUU\n");
    scanf("%d", &op);
    switch(op){
    case 1:
        mostrarPeliculasCA(p,a, TAMPELI, TAM);
        break;
    case 2:
        mostrarPeliculasSA(p, TAMPELI);
        break;
    case 3:
        mostrarPorEstreno(p, TAMPELI);
        break;
    case 4:
        mostrarPorPais(a, TAM);
        break;
    case 5:
        mostrarTodo(p,a,TAMPELI, TAM);
        break;
    case 6:
        mostrarInAmerica(p,a,TAMPELI, TAM);
    }

}
