#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#endif // FUNCIONES_H

void codificar(int semilla , int metodo, string nombre , string salida);

void decodificar(int semilla , int metodo, string nombre , string salida);

void lect_print(string nombre_archivo);

void save(string nombre,string texto,int metodo,int semilla);

void saveDeco(string nombre,string texto);

string binario(int digito);

string texto_bin(string nombre_archivo);

string texto_deco(string texto_para_volver_legible);

string lect_copy(string nombre_archivo);
