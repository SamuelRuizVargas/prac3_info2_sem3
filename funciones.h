#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#endif // FUNCIONES_H

/*
 * El programa utiliza un menu simple en el que el usuario selecciona que desea hacer
 * codificar, decodificar, etc. Una vez seleccionada una opcion el programa procede
 * a preguntarle al usuario las caracteristicas que desea por orden para poder llamar a
 * la funcion, cuando se piden los datos se indican que valores puede elegir y evita aceptar
 * ciertos valores (excepciones), finalmente realiza la accion pedida.
 */

void codificar(int semilla , int metodo, string nombre , string salida);//codifica un archivo de txt que este en la carpeta de archivostxt

void decodificar(int semilla , int metodo, string nombre , string salida);//decodifica un archivo codificado previamente

void lect_print(string nombre_archivo);//lee e imprime todo lo que hay en un txt

void save(string nombre,string texto,int metodo,int semilla);//guarda la codificacion en un archivo

void saveDeco(string nombre,string texto);//guarda la decodificacion en un archivo

string binario(int digito);//pasa un numero a binario

string texto_bin(string nombre_archivo);//pasa el .txt a binario

string texto_deco(string texto_para_volver_legible);//pasa el texto de binario a lenguaje legible

string lect_copy(string nombre_archivo);//copia todo el texto codificado a un string para poder decodificarlo despues
