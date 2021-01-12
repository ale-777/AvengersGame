#ifndef GLOBALS_H
#define GLOBALS_H
#include <iostream>
#include <fstream>
#include <Mundo.h>
#include "Humanos.h"
#include "arbol.h"
#include "aniquilacion.h"
#include "avengers.h"


extern struct Mundo planeta;
extern struct ListaHumano poblacionMundial;
extern struct Arbol arbolMundial;
extern struct TeamAniquileishon aniquiladores;
extern struct Avengers avengers;

extern struct Hashmap HashmapGlobal[101];

extern struct ListaHumano listaCorvus;
extern struct ListaHumano listaMidnight;
extern struct ListaHumano listaBlack;
extern struct ListaHumano listaNebula;
extern struct ListaHumano listaThanos;
extern struct ListaHumano listaSpiderman;
extern struct ListaHumano listaEbonyMaw;

extern struct ListaHumano listaAntMan;
extern struct Temporal temporal;

//PARA THOR
extern struct ListaHumano listaThor;
extern struct ListaHumano nivelXArbol;

//PARA IRON MAN
extern struct ListaHumano arbolPreOrden;
extern struct ListaHumano listaIronMan;

//PARA SPIDERMAN
extern struct ListaHumano arbolAListaParaSpiderman;
#endif // GLOBALS_H
