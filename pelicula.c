#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"

#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1
#define TRUE 1
#define FALSE 0

void inicializarPelicula(ePelicula l[], eActor la[], int tam, int tamact)
{
    int id[8] = {1,2,3,4,5,6,7,8};
    int codigo[8] = {999,666,555,777,111,222,101,202};
    char titulo[8][50] = {"Terminator", "Thor", "It", "Gladiador","Scary Movie", "Yo soy asi", "Scary Movie 2", "Sexto sentido"};
    int anio[8] = {1984,1999,2000,2001,1004,1005,1006,1007};
    int generoid[8] = {1,1,3,4,2,4,2,4};
    int actorid[8] = {1,5,4,4,4,4,1,1};
    int i;
    int index;
    for (i = 0;i < 8; i++)
    {
        index = indexDisponible(l, tam);
        l[index].estado = OCUPADO;
        l[index].id = id[i];
        l[index].codigo = codigo[i];
        strcpy(l[index].titulo, titulo[i]);
        l[index].anio = anio[i];
        l[index].generoid = generoid[i];
        l[index].actorid = actorid[i];
        l[index].principal = getActor(actorid[i], la, tamact);
    }
}

void mostrarPeliculasCA(ePelicula lista[], eActor listaA[], int tam, int tamact)
{
    int i;
    for(i=0; i< tam;i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            if (lista[i].principal.id != -1)
            {
                eActor aux = getActor(lista[i].actorid,listaA, tamact);
                char nombre[50];
                char genero[10];
                strcpy(genero, generoDePelicula(lista[i].generoid));
                strcpy(nombre, aux.nombre);
                printf(" ID: %d \t ", lista[i].id);
                printf("Codigo: %d \t", lista[i].codigo);
                printf("Titulo: %s \t", lista[i].titulo);
                printf("Fecha: %d \t", lista[i].anio);
                printf("Genero: %s \t", genero);
                printf("Actor Principal: %s", nombre);


                printf("\n");
            }
        }
    }
    system("pause");
    system("cls");
}


void mostrarPeliculasSA(ePelicula lista[], int tam)
{
    int i;
    for(i=0; i< tam;i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            if (lista[i].principal.id == -1)
            {

                printf(" ID: %d \5t Codigo: %d \5t Titulo: %s \15t Fecha: %d \5t Genero: %s \n", lista[i].id, lista[i].codigo, lista[i].titulo, lista[i].anio, generoDePelicula(lista[i].generoid));
            }
        }
    }
    system("pause");
    system("cls");
}


const char * generoDePelicula(int g)
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


ePelicula pedirPelicula(eActor l[], int tam, int idC)
{
    ePelicula p;
    int principalAux;
    int valid = FALSE;
    do
    {
        p.id = idC;

        printf("Ingrese Codigo: ");
        scanf("%d", &p.codigo);

        printf("Ingrese Titulo: ");
        fflush(stdin);
        gets(p.titulo);

        printf("Ingrese año de estreno: ");
        fflush(stdin);
        scanf("%d", &p.anio);

        printf("Ingrese Genero (1- Accion, 2- Comedia, 3-Terror, Default- Otro): ");
        fflush(stdin);
        scanf("%d", &p.generoid);

        printf("Ingrese ID Actor Principal (Ingrese 0 si no hay): ");
         mostrarActores(l, tam);
        fflush(stdin);
        scanf("%d", &principalAux);

        valid = validarAltaPelicula(p,l,principalAux, tam);
        p.estado = OCUPADO;
    }while(valid == FALSE);
    p.principal = getActor(principalAux,l, tam);
    p.actorid = principalAux;
    return p;
}


int insertarPelicula(ePelicula l[], eActor la[], int tam, int idC)
{
    int i;
    i = indexDisponible(l, tam);
    if (i != -1)
    {
        l[i] = pedirPelicula(la, tam, idC);
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
    int i;
    if (p.anio <1894 || p.anio > 2025)
    {
        mostrarError("YearOutOfRange\n");
    }
    if(p.codigo > 999 || p.codigo < 100)
    {
        mostrarError("CodeOutOfRange\n");
        return FALSE;
    }
    int len = strlen(p.titulo);
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
            mostrarError("NoLetterTitle\n");
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
        mostrarError("IDActorNotFound\n");
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

void editarPelicula(ePelicula p[], eActor a[], int tam, int tamActor)
{
    int auxcodigo;
    printf("Ingrese Codigo: ");
    scanf("%d", &auxcodigo);
    fflush(stdin);

    int index = buscarPorCodigo(p,auxcodigo, tam);
    if(index == -1)
    {
        mostrarError("IndexNotFound");
    }
    else
    {   int valido = FALSE;
        int opcion;
        printf("1 - Editar Titulo\n2 - Editar Actor\n3 - Editar año de estreno");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                while(valido == FALSE)
                {
                    printf("Ingrese Titulo: ");
                    fflush(stdin);
                    gets(p[index].titulo);
                    validarAltaPelicula(p[index], a, p[index].principal.id, tamActor);
                }
                break;
            case 2:
                while(valido == FALSE)
                {
                    printf("Ingrese Titulo: ");
                    fflush(stdin);
                    gets(p[index].titulo);
                    validarAltaPelicula(p[index], a, p[index].principal.id, tamActor);
                }
                break;
            case 3:
                while(valido == FALSE)
                {
                    printf("Ingrese año de estreno: ");
                    fflush(stdin);
                    scanf("%d", &p[index].anio);
                    validarAltaPelicula(p[index], a, p[index].principal.id, tamActor);
                }
                break;
            }
    }

}

void mostrarPorEstreno(ePelicula l[], int tam)
{
    int i,j;
    ePelicula tmp;

    for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			if (l[j].anio > l[i].anio)
			{
				tmp = l[i];
				l[i] = l[j];
				l[j] = tmp;
			}
		}
	}
	for(i=0; i< tam;i++)
    {
        if (l[i].estado == OCUPADO)
        {
            printf(" Titulo: %s\n Fecha: %d\n", l[i].titulo, l[i].anio);
            printf("--------------------------\n");
        }
    }
    system("pause");
    system("cls");
}

void mostrarTodo(ePelicula lista[], eActor listaA[], int tam, int tamact)
{
    int i;
    for(i=0; i< tam;i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            if (lista[i].principal.id != -1)
            {
                eActor aux = getActor(lista[i].actorid, listaA, tamact);
                printf(" ID: %d\n Codigo: %d\n Titulo: %s\n Fecha: %d\n Genero: %s\n Actor principal: %s\n", lista[i].id, lista[i].codigo, lista[i].titulo, lista[i].anio, generoDePelicula(lista[i].generoid), aux.nombre);
                printf("--------------------------\n");
            }
            else
            {
                printf(" ID: %d\n Codigo: %d\n Titulo: %s\n Fecha: %d\n Genero: %s\n", lista[i].id, lista[i].codigo, lista[i].titulo, lista[i].anio, generoDePelicula(lista[i].generoid));
                printf("--------------------------\n");
            }
        }
    }
}

void mostrarInAmerica(ePelicula lista[], eActor listaA[], int tam, int tamact)
{
    int i;
    for(i=0; i< tam;i++)
    {
        if (lista[i].estado == OCUPADO)
        {
            eActor aux = getActor(lista[i].actorid, listaA, tamact);
            if(strcmp(aux.pais, "EEUU") == 0)
            {
                printf(" ID: %d\n Codigo: %d\n Titulo: %s\n Fecha: %d\n Genero: %s\n Actor principal: %s\n", lista[i].id, lista[i].codigo, lista[i].titulo, lista[i].anio, generoDePelicula(lista[i].generoid), aux.nombre);
                printf("--------------------------\n");
            }
        }
    }
}

void mostrarError(char error[])
{
    system("cls");
    system("color 47");
    printf("ERROR: %s\n", error);
    system("pause");
    system("color 07");
    system("cls");
}
