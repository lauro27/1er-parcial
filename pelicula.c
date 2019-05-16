#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include "actor.h"
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1
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


ePelicula pedirPelicula(eActor l[], int tam)
{
    ePelicula p;
    int principalAux;
    int valid = FALSE;
    do
    {
        p.id = idCounter;

        printf("Ingrese Codigo: ");
        scanf("%d", &p.codigo);

        printf("Ingrese Titulo: ");
        fflush(stdin);
        gets(p.titulo);

        printf("Ingrese Fecha de estreno: ");
        fflush(stdin);
        gets(p.fecha);

        printf("Ingrese Genero (1- Accion, 2- Comedia, 3-Terror, Default- Otro): ");
        fflush(stdin);
        scanf("%d", &p.generoid);

        printf("Ingrese ID Actor Principal (Ingrese 0 si no hay): ");
        fflush(stdin);
        scanf("%d", &principalAux);

        valid = validarAltaPelicula(p,l,principalAux, tam);
        p.estado = OCUPADO;
    }while(valid == FALSE);
    p.principal = getActor(principalAux,l);
    return p;
}


int insertarPelicula(ePelicula l[], eActor la[], int tam)
{
    int i;
    i = indexDisponible(l, tam);
    if (i != -1)
    {
        l[i] = pedirPelicula(la, tam);
    }
    else{ mostrarError("FullArray");}
    system("cls");
    return i;
}


int indexDisponible(ePelicula l[], int tam)
{
    int i;
    int index = -1;

    for(i = 0; i < tam; i++)
    {
        if (l[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


int validarAltaPelicula(ePelicula p, eActor l[], int prin, int tam)
{
    if(p.codigo < 999 && p.codigo >= 100)
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
    for(i=0; i< tam; i++)
    {
        if(prin == l[i].id)
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

int buscarPorCodigo(ePelicula l[],int cod, int tam)
{
    int i;
    for(i=0; i< tam; i++)
    {
        if (cod == l[i].codigo)
        {
            return i;
        }
    }
    return -1;
}

void borrarPelicula(ePelicula l[], int tam)
{
    int auxcod;
    scanf("%d",&auxcod);
    int index = buscarPorCodigo(l,auxcod,tam);
    if(index!= -1)
    {
        l[index].estado = BORRADO;
        printf("Pelicula borrada");
        system("pause");
    }
    else
    {
        mostrarError("Codigo no encontrado");
    }
}

ePelicula editarPelicula(ePelicula p, int tam)
{
    int opcion;
    printf("1 - Editar Titulo\n2 - Editar Actor\n3 - Editar año de estreno");
    switch(opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            }
}

void mostrarPorEstreno(ePelicula l[], int tam)
{
    int i,j;
    ePelicula extralista[tam] = l;
    for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			if (extralista[j] > extralista[i])
			{
				int tmp = extralista[i];
				extralista[i] = extralista[j];
				extralista[j] = tmp;
			}
		}
	}
	for(i=0; i< tam;i++)
    {
        if (extralista[i].estado == OCUPADO)
        {
            printf(" ID: %d\n Codigo: %d\n Titulo: %s\n Fecha: %s\n Genero: %s\n Actor principal: %s\n", extralista[i].id, extralista[i].codigo, extralista[i].titulo, extralista[i].titulo, extralista[i].fecha, generoDePelicula(extralista[i].generoid), extralista[i].principal.nombre);
            printf("--------------------------");
        }
    }
    system("pause");
    system("cls");
}

void mostrarError(char error[])
{
    system("cls");
    system("color 47");
    printf("ERROR: %s\n", error);
    system("pause");
    system("color 07");
}
