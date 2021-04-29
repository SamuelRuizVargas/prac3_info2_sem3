#include "funciones.h"

void codificar(int semilla , int met, string nom , string sali)
{
    string texto_en_bin=texto_bin(nom);
    if (met==1)
    {
        int posi=0,posi2=0, len=texto_en_bin.length(), unos=0, ceros=0;
        string textofin,texto,textoaux,letra;
        int limite_ite=(len-1)/semilla, limite_interno;
        for (int i=0;i<=limite_ite;i++)
        {
            if(i==0)//si es la primera vez se invierte todo
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_en_bin[posi];
                    texto+=letra;
                    posi++;
                }
                textoaux="";
                for (int j=0;j<=semilla-1;j++)
                {
                    letra=texto[j];
                    if(letra=="1")
                        textoaux+="0";
                    else
                        textoaux+="1";
                }
                textofin+=textoaux;
                posi=0;
            }
            else//si no es la primera vez revisar el bloque anterior
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_en_bin[posi];
                    texto+=letra;
                    posi++;
                }
                textoaux="";
                ceros=0;
                unos=0;
                for (int j=0;j<=semilla-1;j++)//se cuentan cuantos 0's y 1's hay
                {
                    letra=texto[j];
                    if(letra=="1")
                        unos++;
                    else
                        ceros++;
                }
                if(unos>ceros)//si hay mas 1's que 0's
                {
                    texto="";
                    for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                    {
                        if (posi>=len)
                            break;
                        letra=texto_en_bin[posi];
                        texto+=letra;
                        posi++;
                    }
                    limite_interno=texto.length();
                    posi-=semilla;
                    posi2=0;
                    for(int k=0;k<=limite_interno-1;k++)
                    {
                        letra=texto[k];
                        if(posi2==2)
                        {
                            if(letra=="1")
                                letra="0";
                            else
                                letra="1";
                            posi2=-1;
                        }
                        textoaux+=letra;
                        posi2++;
                    }
                }
                else if(ceros>unos)//si hay mas 0's que 1's
                {
                    texto="";
                    for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                    {
                        if (posi>=len)
                            break;
                        letra=texto_en_bin[posi];
                        texto+=letra;
                        posi++;
                    }
                    limite_interno=texto.length();
                    posi-=semilla;
                    posi2=0;
                    for(int k=0;k<=limite_interno-1;k++)
                    {
                        letra=texto[k];
                        if(posi2==1)
                        {
                            if(letra=="1")
                                letra="0";
                            else
                                letra="1";
                            posi2=-1;
                        }
                        textoaux+=letra;
                        posi2++;
                    }
                }
                else//si hay igual cantidad de 1's que de 0's se invierte todo
                {
                    texto="";
                    for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                    {
                        if (posi>=len)
                            break;
                        letra=texto_en_bin[posi];
                        texto+=letra;
                        posi++;
                    }
                    limite_interno=texto.length();
                    posi-=semilla;
                    for (int k=0;k<=limite_interno-1;k++)
                    {
                        letra=texto[k];
                        if(letra=="1")
                            letra="0";
                        else
                            letra="1";
                        textoaux+=letra;
                    }
                }
                textofin+=textoaux;
            }
        }
        save(sali,textofin,met,semilla);
    }
    else
    {
        int posi=0,len=texto_en_bin.length(),nueva_pos;
        string textofin,texto,textoaux,letra;
        char pasochar;
        int limite_ite=(len-1)/semilla,limite_interno;
        for (int i=0;i<=limite_ite;i++)
        {
            texto="";
            for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
            {
                if (posi>=len)
                    break;
                letra=texto_en_bin[posi];
                texto+=letra;
                posi++;
            }
            limite_interno=texto.length();
            textoaux=texto;
            for(int k=0;k<=limite_interno-1;k++)
            {
                pasochar=texto[k];
                nueva_pos=k+1;
                if(nueva_pos>limite_interno-1)
                    nueva_pos=0;
                if(pasochar=='1' or pasochar=='0')
                    textoaux[nueva_pos]=pasochar;
            }
            textofin+=textoaux;
        }
        save(sali, textofin, met,semilla);
    }
}

void decodificar (int semilla , int met, string nom , string sali)
{
    string texto_codificado=lect_copy(nom), textonormal;
    if (met==1)
    {
        int posi=0,posi2=0, len=texto_codificado.length(), unos=0, ceros=0;
           string textofin,texto,textoaux,textoaux2,letra;
           int limite_ite=(len-1)/semilla,limite_interno;
           for (int i=0;i<=limite_ite;i++)
           {
               if(i==0)//si es la primera vez se invierte todo
               {
                   texto="";
                   for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                   {
                       if (posi>=len)
                           break;
                       letra=texto_codificado[posi];
                       texto+=letra;
                       posi++;
                   }
                   textoaux="";
                   for (int j=0;j<=semilla-1;j++)
                   {
                       letra=texto[j];
                       if(letra=="1")
                           textoaux+="0";
                       else
                           textoaux+="1";
                   }
                   textofin+=textoaux;
                   textoaux2=textoaux;
                   posi=0;
               }
               else//si no es la primera vez revisar el bloque anterior
               {
                   texto="";
                   for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                   {
                       if (posi>=len)
                           break;
                       letra=texto_codificado[posi];
                       texto+=letra;
                       posi++;
                   }
                   ceros=0;
                   unos=0;
                   for (int j=0;j<=semilla-1;j++)//se cuentan cuantos 0's y 1's hay
                   {
                       letra=textoaux2[j];
                       if(letra=="1")
                           unos++;
                       else
                           ceros++;
                   }
                   textoaux2="";
                   if(unos>ceros)//si hay mas 1's que 0's
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       posi2=0;
                       for(int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(posi2==2)
                           {
                               if(letra=="1")
                                   letra="0";
                               else
                                   letra="1";
                               posi2=-1;
                           }
                           textoaux2+=letra;
                           posi2++;
                       }
                   }
                   else if(ceros>unos)//si hay mas 0's que 1's
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       posi2=0;
                       for(int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(posi2==1)
                           {
                               if(letra=="1")
                                   letra="0";
                               else
                                   letra="1";
                               posi2=-1;
                           }
                           textoaux2+=letra;
                           posi2++;
                       }
                   }
                   else//si hay igual cantidad de 1's que de 0's se invierte todo
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       for (int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(letra=="1")
                               letra="0";
                           else
                               letra="1";
                           textoaux2+=letra;
                       }
                   }
                   textofin+=textoaux2;
               }
           }
           textonormal=texto_deco(textofin);
           saveDeco(sali, textonormal);
    }
    else
    {
        int posi=0,len=texto_codificado.length(),nueva_pos;
            string textofin,texto,textoaux,letra;
            char pasochar;
            int limite_ite=(len-1)/semilla,limite_interno;
            for (int i=0;i<=limite_ite;i++)
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_codificado[posi];
                    texto+=letra;
                    posi++;
                }
                limite_interno=texto.length();
                textoaux=texto;
                for(int k=0;k<=limite_interno-1;k++)
                {
                    pasochar=texto[k];
                    nueva_pos=k-1;
                    if(nueva_pos<0)
                        nueva_pos=limite_interno-1;
                    if(pasochar=='1' or pasochar=='0')
                        textoaux[nueva_pos]=pasochar;
                }
                textofin+=textoaux;
            }
            textonormal=texto_deco(textofin);
            saveDeco(sali, textonormal);
    }
}

void lect_print(string nombre)//lee e imprime todo lo que hay en un txt
{
    ifstream archivo;
    string texto;
    archivo.open("../practica3/archivostxt/"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}

void save(string nombre, string texto, int metodo, int semilla) //guarda la codificacion en un archivo
{
    ofstream escritura;
    string met=to_string(metodo), semi=to_string(semilla);
    string nombre_completo=nombre+"_met"+met+"_sem"+semi+".txt";
    escritura.open("../practica3/archivostxt/"+nombre_completo);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

void saveDeco(string nombre, string texto) //guarda la codificacion en un archivo
{
    ofstream escritura;
    string nombre_completo=nombre+"(decodificado)"+".txt";
    escritura.open("../practica3/archivostxt/"+nombre_completo);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

string binario(int digi)//pasa un numero a binario
{
    string binario, caracter,binar;
    for (int i=0;i<8;i++)
    {
        caracter=to_string(digi%2);
        binario+=caracter;
        digi/=2;
    }
    for (int i=7;i>=0;i--)
    {
        caracter=binario[i];
        binar+=caracter;
    }
    return binar;
}

string texto_bin(string nombre) //pasa el .txt a binario
{
    ifstream archivo;
    string texto,caracter,bin;
    char caracter2;
    int numero;
    archivo.open("../practica3/archivostxt/"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        caracter2=archivo.get();
        if (archivo.eof())
            break;
        numero=caracter2;
        bin=binario(numero);
        texto+=bin;
    }
    archivo.close();
    return texto;
}

string texto_deco(string binario) //pasa el texto de binario a lenguaje legible
{
    int posi=0,len=binario.length();
    string textofin, texto, letra,texto2;
    int limite_ite=(len-1)/8, numero, suma;
    char caracter;
    for (int i=0;i<=limite_ite;i++)
    {
        texto="";
        suma=0;
        for(int k=0;k<=7;k++)//se saca el bloque segun la semilla y se guarda en texto
        {
            letra=binario[posi];
            texto+=letra;
            posi++;
        }
        texto2="";
        for(int k=7;k>=0;k--)
        {
            letra=texto[k];
            texto2+=letra;
        }
        texto=texto2;
        for (int k=0;k<=7;k++)
        {
            letra=texto[k];
            if(letra=="1")
            {
                numero= pow(2,k);
                suma+=numero;
            }
        }
        caracter=suma;
        textofin+=caracter;
    }
    return textofin;
}

string lect_copy(string nombre) //copia todo el texto codificado a un string para poder decodificarlo despues
{
    ifstream archivo;
    string texto, textofin;
    archivo.open("../practica3/archivostxt/"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        if (archivo.eof())
            break;
        getline(archivo,texto);
        textofin+=texto;
    }
    archivo.close();
    return textofin;
}
