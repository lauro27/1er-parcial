#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include "actor.h"

void inicializarActor(eActor l[])
{
    l[1].id = 1;
    strcpy(l[1].nombre, "Julieta Roberto");
    strcpy(l[1].pais, "EEUU");
    l[2].id = 2;
    strcpy(l[2].nombre, "Roberto Deniro");
    strcpy(l[2].pais, "EEUU");
    l[3].id = 3;
    strcpy(l[3].nombre, "Richar Darin");
    strcpy(l[3].pais, "Argentina");
    l[4].id = 4;
    strcpy(l[4].nombre, "Tita Merelo");
    strcpy(l[4].pais, "Argentina");
    l[5].id = 5;
    strcpy(l[5].nombre, "Sandro");
    strcpy(l[5].pais,"Argentina");
}

eActor getActor(int aux, eActor l[])
{
    int i;
    for(i=0; i<sizeof(l); i++)
    {
        if(aux == l[i].id)
            {
                return l[i];
            }
    }
    return l[i];
}
