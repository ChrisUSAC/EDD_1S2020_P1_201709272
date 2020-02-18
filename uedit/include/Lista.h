#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Lista
{
    public:
        //metodo constructor
        Lista();
        //metodo destructor
        virtual ~Lista();
        NodoLista* primero; // puntero que hace referencia al inicio de la lista
        NodoLista* ultimo; // puntero que hace referencia al final de la lista
        int tam; //tamano de la listas
        bool estaVacia(); // metodo que informa si la lista esta vacia
        void insertar(string palabraBus, string palabraRemp); // metodo que inserta de forma ordenada en lista
        NodoLista* insertarAt(int indice, NodoLista* n);//inserta entre otros nodos

        void imprimir();//imprime en consola la lista


        int encontrarIndice(string palabraBus,NodoLista* prim); // metodo que retorna el indice donde se insertara el nodo


        void graficar(); // metodo que realiza el graphiz
        void escribir(); // escribe la sintaxis dot para el reporte

        void graficar2(); // metodo que realiza el graphiz
        void escribir2(); // escribe la sintaxis dot para el reporte

    protected:

    private:
};

#endif // LISTA_H
