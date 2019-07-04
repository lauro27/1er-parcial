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
void segundoMostrar(ePelicula[], eActor[]);



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
        printf("1 - ALTA\n2 - MODIFICAR\n3 - BAJA\n4 - MOSTRAR\n5 - ---RECUPERATORIO---\n6 - SALIR\n");
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
                segundoMostrar(listaPelicula, listaActor);
                break;
            case 6:
                end = TRUE;
                break;
            }
    }while(end == FALSE);
    return 0;
}

void menuMostrar(ePelicula p[], eActor a[])
{
    int op;
    printf("1 - Mostrar peliculas con actor principal\n2 - Mostrar peliculas sin actor principal\n3 - Mostrar peliculas ordenadas por año de estreno\n4 - Mostrar actores ordenados por país\n5 - Mostrar Todo\n6 - Mostrar Actores de EEUU\n");
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

void segundoMostrar(ePelicula p[], eActor a[])
{
    int op;
    printf("1 - Mostrar actores por edad\n2 - Mostrar Actores mayores de edad\n3 - Dar alta de Actor\n4 - Modificar actor\n5 - Mostrar segun pais\n6 - Dar baja segun pais\n");
    scanf("%d", &op);
    switch(op){
    case 1:
        mostrarActoresEdad(a, TAM);
        break;
    case 2:
        mostrarActoresMayores(a, TAM);
        break;
    case 3:
        insertarActor(a,TAM);
        break;
    case 4:
        modificarActor(a,TAM);
        break;
    case 5:
        mostrarActoresPais(a,TAM);
        break;
    case 6:
        borrarActoresPais(a,TAM);
        break;

    }
    system("pause");
    system("cls");

}
