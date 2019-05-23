#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"

void inicializarActor(eActor l[])
{
    l[0].id = 1;
    strcpy(l[0].nombre, "Julieta Roberto");
    strcpy(l[0].pais, "EEUU");
    l[1].id = 2;
    strcpy(l[1].nombre, "Richar Darin");
    strcpy(l[1].pais, "Argentina");
    l[2].id = 3;
    strcpy(l[2].nombre, "NicoleKidman");
    strcpy(l[2].pais, "Australia");
    l[3].id = 4;
    strcpy(l[3].nombre, "Tita Merelo");
    strcpy(l[3].pais, "Argentina");
    l[4].id = 5;
    strcpy(l[4].nombre, "Natalia Oreiro");
    strcpy(l[4].pais,"Uruguay");
}

eActor getActor(int aux, eActor l[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(aux == l[i].id)
            {
                return l[i];
            }
    }
    return l[i];
}

void mostrarPorPais(eActor elista[],int tam)
{
    int i,j;
    for (i = 0; i < tam-1; i++)
	{
		for (j = i+1; j < tam; j++)
		{
			if (strcmp(elista[j].pais, elista[i].pais) < 1)
			{
				eActor tmp = elista[i];
				elista[i] = elista[j];
				elista[j] = tmp;
			}
		}
	}
	for(i=0; i< tam;i++)
    {
            printf(" ID: %d\n Nombre: %s\n Pais: %s\n", elista[i].id, elista[i].nombre, elista[i].pais);
            printf("--------------------------");
    }
    system("pause");
    system("cls");
}

void mostrarActores(eActor l[], int tam)
{
    int i;
    printf("ID\tNombre\tNacionalidad");
    for(i=0; i< tam;i++)
    {
        printf("%d\t%s\t%s", l[i].id, l[i].nombre, l[i].pais);
    }
}
