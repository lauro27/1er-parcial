#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"
#define TRUE 1
#define FALSE 0

void inicializarActor(eActor l[])
{
    l[0].id = 1;
    strcpy(l[0].nombre, "Julieta Roberto");
    strcpy(l[0].pais, "EEUU");
    l[0].edad = 33;
    l[1].id = 2;
    strcpy(l[1].nombre, "Richar Darin");
    strcpy(l[1].pais, "Argentina");
    l[1].edad = 77;
    l[2].id = 3;
    strcpy(l[2].nombre, "NicoleKidman");
    strcpy(l[2].pais, "Australia");
    l[2].edad = 11;
    l[3].id = 4;
    strcpy(l[3].nombre, "Tita Merelo");
    strcpy(l[3].pais, "Argentina");
    l[3].edad = 18;
    l[4].id = 5;
    strcpy(l[4].nombre, "Natalia Oreiro");
    strcpy(l[4].pais,"Uruguay");
    l[4].edad = 33;
    l[5].id = 0;
    l[6].id = 0;
    l[7].id = 0;
    l[8].id = 0;
    l[9].id = 0;


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
        if(elista[i].id != 0)
        {
            printf("%5d %30s %20s %d\n", elista[i].id, elista[i].nombre, elista[i].pais, elista[i].edad);
            printf("--------------------------\n");
        }
    }
    system("pause");
    system("cls");
}

void mostrarActores(eActor l[], int tam)
{
    int i;
    printf("ID\tNombre\tNacionalidad\n");
    for(i=0; i< tam;i++)
    {
        if(l[i].id != 0)
        {
            printf("%3d %30s %30s %3d\n", l[i].id, l[i].nombre, l[i].pais, l[i].edad);
        }
    }
}

void mostrarActoresEdad(eActor l[], int tam)
{
    int i,j;
    eActor aux;
    for(i = 0; i<tam-1; i++)
    {
        for(j = i+1; j<(tam-1); j++)
        {
            if (l[i].edad < l[j].edad)
            {
                aux = l[i];
                l[i] = l[j];
                l[j] = aux;
            }
        }

    }
    mostrarActores(l, tam);
}

void mostrarActoresMayores(eActor l[],int tam)
{
    int i;
    printf("ID\tNombre\tNacionalidad\n");
    for(i = 0; i <tam; i++)
    {
        if (l[i].edad>= 18 &&l[i].id != 0)
        {
            printf("%3d %30s %30s %3d\n", l[i].id, l[i].nombre, l[i].pais, l[i].edad);
        }
    }
}

void insertarActor(eActor l[], int tam)
{
    //buscar lugar libre
    int i, index;
    int found = FALSE;
    for(i =0; i<tam; i++)
    {
        if (l[i].id == 0)
        {
            index = i;
            found = TRUE;
            break;
        }
     }
    if (found == TRUE)
    {
        l[index].id = index+1;
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(l[index].nombre);

        printf("Ingrese Pais: ");
        fflush(stdin);
        gets(l[index].pais);

        int edadCheck = FALSE;
        int edadaux;
        while(edadCheck == FALSE)
        {
            printf("Ingrese edad: ");
            scanf("%d", &edadaux);

            if (edadaux >= 0)
            {
                l[index].edad = edadaux;
                edadCheck = TRUE;
            }
            else
            {
                mostrarError("AgeOutOfRange");
            }

        }

    }
    else
    {
        mostrarError("FullArray");
    }
}

int modificarActor(eActor l[],int tam)
{
    int i, idaux, index = -1;
    mostrarActores(l, tam);
    printf("Ingrese ID: ");
    scanf("%d", &idaux);
    for (i = 0; i < tam; i++)
    {
        if(idaux == l[i].id && idaux != 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        mostrarError("IDNotFound");
        return 0;
    }
    int op;
    printf("\n\n1 - Modificar nombre(Actualmente: %s)\n2 - Modificar Nacionalidad(Actualmente: %s)\n3 - Modificar Edad(Actualmente: %d)\n", l[index].nombre, l[index].pais,l[index].edad);
    scanf("%d", &op);
    switch(op)
    {
    case 1:
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(l[index].nombre);
        break;
    case 2:
        printf("Ingrese Pais: ");
        fflush(stdin);
        gets(l[index].pais);
        break;
    case 3:
        printf("\n");//linea agregada para complacer al compilador
        int edadCheck = FALSE;
        int edadaux;
        while(edadCheck == FALSE)
        {
            printf("Ingrese edad: ");
            scanf("%d", &edadaux);

            if (edadaux >= 0)
            {
                l[index].edad = edadaux;
                edadCheck = TRUE;
            }
            else
            {
                mostrarError("AgeOutOfRange");
            }

        }
        break;
    }
}

void mostrarActoresPais(eActor l[],int tam)
{
    char paisaux[30];
    int found = FALSE;
    printf("Ingrese Pais: ");
    fflush(stdin);
    gets(paisaux);

    int i;
    for(i = 0; i <tam; i++)
    {
        if (strcmp(l[i].pais,paisaux) == 0)
        {
            printf("%3d %30s %30s %3d\n", l[i].id, l[i].nombre, l[i].pais, l[i].edad);
            found = TRUE;
        }
    }
    if (found = FALSE)
    {
        mostrarError("CountryNotFound");
    }

}

void borrarActoresPais(eActor l[],int tam)
{
    char paisaux[30];
    int found = FALSE;
    printf("Ingrese Pais: ");
    fflush(stdin);
    gets(paisaux);

    int i;
    for(i = 0; i <tam; i++)
    {
        if (strcmp(l[i].pais,paisaux) == 0)
        {
            l[i].id =0;
            found = TRUE;
        }
    }
    if (found == TRUE)
    {
        printf("Actores de %s borrados\n", paisaux);
    }
    else if(found == FALSE)
    {
        mostrarError("CountryNotFound");
    }

}
