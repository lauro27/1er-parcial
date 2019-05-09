#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char pais[20];
}eActor;

#endif // ACTOR_H_INCLUDED


void inicializarActor(eActor[]);

eActor getActor();
