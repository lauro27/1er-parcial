#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char pais[20];
    int edad;
}eActor;

#endif // ACTOR_H_INCLUDED


/** \brief Inicializa el array de actores
 *
 * \param eActor[] Array a completar
 * \return void
 *
 */
void inicializarActor(eActor[]);

/** \brief Busca al actor por ID
 *
 * \param int: ID a buscar
 * \param eActor[] Array de actores
 * \return eActor Estructura de Actor
 *
 */
eActor getActor(int, eActor[], int);

void mostrarPorPais(eActor [], int);

void mostrarActores(eActor [], int);

void mostrarActoresEdad(eActor [], int);

void mostrarActoresMayores(eActor [], int);

void insertarActor(eActor [], int);

int modificarActor(eActor [],int);

void mostrarActoresPais(eActor [],int );

void borrarActoresPais(eActor [],int);
