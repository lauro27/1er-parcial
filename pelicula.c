#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include "actor.h"
#define LIBRE 0
#define OCUPADO 1
#define TRUE 1
#define FALSE 0

void mostrarPeliculasCA(ePelicula lista[])
{
    int i;
    for(i=0; i< sizeof(lista);i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            if (lista[i].principal.id != -1)
            {
                printf(" ID: %d\n Codigo: %d\n Titulo: %s\n Fecha: %s\n Genero: %s\n Actor principal: %s\n", lista[i].id, lista[i].codigo, lista[i].titulo, lista[i].titulo, lista[i].fecha, generoDePelicula(lista[i].generoid), lista[i].principal.nombre);
                printf("--------------------------");
            }
        }
    }
    system("pause");
    system("cls");
}


void mostrarPeliculasSA(ePelicula lista[])
{
    int i;
    for(i=0; i< sizeof(lista);i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            if (lista[i].principal.id == -1)
            {

                printf(" ID: %d\n Codigo: %d\n Titulo: %s\n Fecha: %s\n Genero: %s\n", lista[i].id, lista[i].codigo, lista[i].titulo, lista[i].titulo, lista[i].fecha, generoDePelicula(lista[i].generoid));
                printf("--------------------------");
            }
        }
    }
    system("pause");
    system("cls");
}


char generoDePelicula(int g)
{
    switch(g){
    case 1:
        return "Accion";
        break;
    case 2:
        return "Comedia";
        break;
    case 3:
        return "Terror";
        break;
    default:
        return "Otro";
        break;
    }
}


ePelicula pedirPelicula(eActor l[])
{
    ePelicula p;
    int principalAux;
    int valid = FALSE;
    do
    {
        p.id = idCounter;

        printf("Ingrese Codigo: ");
        scanf("&d", &p.codigo);

        printf("Ingrese Titulo: ");
        fflush(stdin);
        gets(p.titulo);

        printf("Ingrese Fecha de estreno: ");
        fflush(stdin);
        gets(p.fecha);

        printf("Ingrese Genero (1- Accion, 2- Comedia, 3-Terror, Default- Otro): ");
        fflush(stdin);
        gets(p.generoid);

        printf("Ingrese ID Actor Principal (Ingrese 0 si no hay): ");
        fflush(stdin);
        scanf("%d", &principalAux);

        valid = validarAltaPelicula(p);
        p.estado = OCUPADO;
    }while(valid == FALSE);
    p.principal = getActor(principalAux,l);
    return p;
}


int insertarPelicula(ePelicula l[], eActor la[])
{
    int i;
    i = indexDisponible(l);
    if (i != -1)
    {
        l[i] = pedirPelicula(la);
    }
    else{ mostrarError("FullArray");}
    system("cls");
    return i;
}


int indexDisponible(ePelicula l[])
{
    int i;
    int index = -1;

    for(i = 0; i < sizeof(l); i++)
    {
        if (l[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


int validarAltaPelicula(ePelicula p, eActor l[], int prin)
{
    if(p.codigo < 999 && p.codigo >= 0)
    {
        mostrarError("Codigo fuera de rango(0 - 999) \nIntente nuevamente\n");
        return FALSE;
    }
    ///AGREGAR CHECK TITULO4857
    int len = strlen(p.titulo);
    int i;
    int tituloletras = FALSE;
    for(i = 0; i< len; i++)
    {
         if (!(p.titulo[i] >=48 && p.titulo[i]<= 57))
         {
             tituloletras = TRUE;
             break;
         }
    }
    if (tituloletras == FALSE)
        {
            mostrarError("Titulo sin letras\n Intente nuevamente\n");
            return FALSE;
        }
    int check = FALSE;
    for(i=0; i< sizeof(l); i++)
    {
        if(prin == l.id)
        {
            check = prin;

        }
    }
    if(check == FALSE && prin != 0)
    {
        mostrarError("Id Actor no encontrado\nIntente nuevamente\n");
        return FALSE;
    }
    return TRUE;

}



void mostrarError(char error[])
{
    system("cls");
    system("color 47");
    printf("ERROR: %s\n", error);
    system("pause");
    system("color 07");
}
