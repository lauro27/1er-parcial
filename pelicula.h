#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include "actor.h"

typedef struct
{
    int estado;
    int id;
    int codigo;
    char titulo[50];
    int anio;
    int generoid;
    int actorid;
    eActor principal;
}ePelicula;

#endif // PELICULA_H_INCLUDED

void inicializarPelicula(ePelicula[], eActor[], int, int);

/** \brief Muestra las peliculas que no tienen actor principal en el(si principal.id == -1)
 *
 * \param [] ePelicula: lista de todas las peliculas
 * \return void
 *
 */
void mostrarPeliculasSA(ePelicula [], int);

/** \brief Muestra las peliculas que tienen actor principal(si principal id != -1)
 *
 * \param [] ePelicula: lista de todas las peliculas
 * \return void
 *
 */
void mostrarPeliculasCA(ePelicula [], eActor[], int);


/** \brief Usado en mostrarPeliculaCA y mostrarPeliculaSA para cambiar los id de genero por strings con el genero correspondiente
 *
 * \param int: ID del genero (1- accion, 2- comedia, 3- terror, default- otro)
 * \return char: Genero correspondiente
 *
 */
const char * generoDePelicula(int);

/** \brief Usado en agregarPelicula para pedirle los datos al usuario
 *
 * \return ePelicula: Resultado final de la carga de datos
 *
 */
ePelicula pedirPelicula(eActor [], int, int);

/** \brief Agrega una pelicula al array pidiendole datos al usuario
 *
 * \param ePelicula[]: Array de peliculas
 * \return void
 *
 */
int insertarPelicula(ePelicula [], eActor[], int, int);

/** \brief Revisa si hay lugar en el array para insertar una pelicula (devuelve indice en el array o -1 si no hay lugar)
 *
 * \param ePelicula[]: Array a revisar
 * \return int: Indice disponible o -1 si no hay disponible
 *
 */
int indexDisponible(ePelicula[], int);

/** \brief Revisa si el actor existe, si el codigo esta en rango, y si el titulo contiene letras
 *
 * \param ePelicula: Datos a validar
 * \return int: Retorna 1 si es valido y 0 si no
 *
 */
int validarAltaPelicula(ePelicula, eActor[], int, int);

/** \brief Busca en el array una pelicula segun el codigo
 *
 * \param ePelicula[]: Array de peliculas
 * \param int: Codigo de busqueda
 * \param int: Tamaño del array
 * \return int: Indice en el array de la pelicula o -1 si el codigo no se encuentra
 *
 */
int buscarPorCodigo(ePelicula[],int, int);

/** \brief Borra una pelicula del array, muestra un error si el codigo es erroneo
 *
 * \param ePelicula[]: Array de peliculas
 * \param int: tamaño del array
 * \return void
 *
 */
void borrarPelicula(ePelicula[], int);

void editarPelicula(ePelicula[], eActor[], int, int);//COMPLETAR

void mostrarPorEstreno(ePelicula[], int);

void mostrarTodo(ePelicula[],eActor[], int);

void mostrarInAmerica(ePelicula[], eActor[], int);

/** \brief Muestra un error con un mensaje.
 *
 * \param [] char: Mensaje a mostrar en el error.
 * \return void
 *
 */
void mostrarError(char []);


