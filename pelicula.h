#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include "actor.h"
int idCounter = 1000;
typedef struct
{
    int estado;
    int id;
    int codigo;
    char titulo[50];
    char fecha[20];
    int generoid;
    eActor principal;
}ePelicula;

#endif // PELICULA_H_INCLUDED

/** \brief Muestra las peliculas que no tienen actor principal en el(si principal.id == -1)
 *
 * \param [] ePelicula: lista de todas las peliculas
 * \return void
 *
 */
void mostrarPeliculasSA(ePelicula []);

/** \brief Muestra las peliculas que tienen actor principal(si principal id != -1)
 *
 * \param [] ePelicula: lista de todas las peliculas
 * \return void
 *
 */
void mostrarPeliculasCA(ePelicula []);


/** \brief Usado en mostrarPeliculaCA y mostrarPeliculaSA para cambiar los id de genero por strings con el genero correspondiente
 *
 * \param int: ID del genero (1- accion, 2- comedia, 3- terror, default- otro)
 * \return char: Genero correspondiente
 *
 */
char generoDePelicula(int);

/** \brief Usado en agregarPelicula para pedirle los datos al usuario
 *
 * \return ePelicula: Resultado final de la carga de datos
 *
 */
ePelicula pedirPelicula();

/** \brief Agrega una pelicula al array pidiendole datos al usuario
 *
 * \param ePelicula[]: Array de peliculas
 * \return void
 *
 */
int insertarPelicula(ePelicula [], eActor[]);

/** \brief Revisa si hay lugar en el array para insertar una pelicula (devuelve indice en el array o -1 si no hay lugar)
 *
 * \param ePelicula[]: Array a revisar
 * \return int: Indice disponible o -1 si no hay disponible
 *
 */
int indexDisponible(ePelicula[]);

/** \brief Revisa si el actor existe, si el codigo esta en rango, y si el titulo contiene letras
 *
 * \param ePelicula: Datos a validar
 * \return int: Retorna 1 si es valido y 0 si no
 *
 */
int validarAltaPelicula(ePelicula);



/** \brief Muestra un error con un mensaje.
 *
 * \param [] char: Mensaje a mostrar en el error.
 * \return void
 *
 */
void mostrarError(char []);
