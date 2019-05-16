#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"
#include "pelicula.h"


#define TRUE 1
#define FALSE 0
#define TAM 5
#define TAMPELI 10

void menuMostrar(ePelicula[], eActor[]);

int main()
{
    ePelicula listaPelicula[TAM];
    eActor listaActor[TAM];
    inicializarActor(listaActor);
    int i;
    for(i = 0; i<sizeof(listaPelicula); i++)
    {
        listaPelicula[i].estado = 0;
    }
    int end = FALSE;
    int opcion;
    do{
        printf("1 - ALTA\n2 - MOSTRAR\n3 - SALIR");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                insertarPelicula(listaPelicula, listaActor, TAMPELI);
                break;
            case 2:
                menuMostrar(listaPelicula, listaActor);
                break;
            case 3:
                end = TRUE;
                break;
            }
    }while(end == FALSE);
    return 0;
}

void menuMostrar(ePelicula p[], eActor a[])
{
    int op;
    printf("1 - Mostrar peliculas con actor principal\n2 - Mostrar peliculas sin actor principal\n");
    scanf("%d", &op);
    switch(op){
    case 1:
        mostrarPeliculasCA(p);
        break;
    case 2:
        mostrarPeliculasSA(p);
        break;
    }

}
