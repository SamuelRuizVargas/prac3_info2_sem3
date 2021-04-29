#include <iostream>

#include "funciones.h"

using namespace std;

int main()
{
        int opcion;
        cout << "Practica 3 - Samuel Ruiz Vargas - CC: 1000898936"<<endl<<endl;

        bool terminar=false;
        int term;
        while (terminar==false)
        {
            cout<<"1 - Codificar un texto"<<endl;
            cout<<"2 - Decodificar un texto"<<endl;
            cout<<"3 - Sistema de cajero"<<endl;
            cout<<"4 - Salir del programa"<<endl<<endl;
            cout<<"Ingrese la opcion deseada: ";cin>>opcion;
            while (opcion<1 or opcion>4)
            {
                cout<<"Opcion invalida."<<endl;
                cout<<"Ingrese la opcion deseada: ";cin>>opcion;
            }

            switch(opcion)
            {
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 1: //codificacion de archivo de texto con cierta semilla
            {
                for (int i=0;i<=50;i++)
                {
                    cout<<endl;
                }
                string nombre,guardar;
                int semi, met;
                cout<<"Bienvenido al sistema de codificacion de texto"<<endl;
                cout<<"Digite el nombre de su archivo(sin extension): ";cin>>nombre;
                nombre+=".txt";
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Esto fue lo que se encontro en el archivo: "<<endl<<endl;
                lect_print(nombre);
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Ingrese que semilla desea usar para la codificacion(entre 2 y 8): ";cin>>semi;
                while (semi<2 or semi>8)
                {
                    cout<<"Ingrese que semilla desea usar para la codificacion(entre 1 y 8): ";cin>>semi;
                }
                cout<<endl;
                cout<<"Ingrese el metodo que desea usar para codificar (1 o 2): ";cin>>met;
                while (met<1 or met>2)
                {
                    cout<<"Ingrese el metodo que desea usar para codificar (1 o 2): ";cin>>met;
                }
                cout<<endl;
                cout<<"NOTA:Al nombre se le agregara el metodo y la semilla usadas por si se desea hacer una decodificacion."<<endl<<endl;
                cout<<"Ingrese el nombre del archivo en el que desea guardarlo(sin extension): ";cin>>guardar;
                codificar(semi,met,nombre,guardar);
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Su texto fue codificado con el metodo "<<met<<" y la semilla "<<semi<<"."<<endl<<endl;
                cout<<endl<<endl;
                cout<<"Archivo guardado, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                while (term<1 or term>2)
                {
                    cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                }
                if(term==1)
                {
                    terminar=true;
                }
                else
                {
                    terminar=false;
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }
                }
            }
                break;
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 2: //Decodificar un archivo de texto con la misma semilla
            {
                for (int i=0;i<=50;i++)
                {
                    cout<<endl;
                }
                string nombre, textobin, texto_codi, letra, guardar;
                int semi, met;
                cout<<"Bienvenido al sistema de decodificacion de texto"<<endl;
                cout<<"Digite el nombre de el archivo(sin extension) que desea decodificar: ";cin>>nombre;
                nombre+=".txt";
                cout<<"Digite en que semilla se codifico originalmente el texto: ";cin>>semi;
                while (semi<2 or semi>8)
                {
                    cout<<"Digite en que semilla se codifico originalmente el texto: ";cin>>semi;
                }
                cout<<"Digite con que metodo se codifico originalmente el texto: ";cin>>met;
                while (met<1 or met>2)
                {
                    cout<<"Digite con que metodo se codifico originalmente el texto: ";cin>>met;
                }
                cout<<endl;
                cout<<"Ingrese el nombre del archivo en el que desea guardarlo(sin extension): ";cin>>guardar;
                decodificar(semi,met,nombre,guardar);
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Su texto fue decodificado."<<endl<<endl;
                cout<<endl<<endl;
                cout<<"Archivo guardado, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                while (term<1 or term>2)
                {
                    cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                }
                if(term==1)
                {
                    terminar=true;
                }
                else
                {
                    terminar=false;
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }
                }
            }
                break;
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 3: //Cajero
            {
            }
                break;
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 4: //Salir
            {
                terminar=true;
            }
                break;
            }
        }
        return 0;
}
