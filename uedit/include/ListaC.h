#ifndef LISTAC_H
#define LISTAC_H
#include"NodoListaC.h"//se incluye el nodo
#include <iostream>
#include<fstream>

using namespace std;

class ListaC
{
    public:
        ListaC();
        virtual ~ListaC();

        bool estaVacia(); // metodo que informa si la lista esta vacia
        void imprimir(); // metodo que imprime la lista en consola
        void insertarFinal(string direccion,string nombre);// metodo que inserta los nuevos nodos al final de la lista

        void graficar();
        void escribir();

        NodoListaC* primero; // puntero que indica cual es el primer nodo de la lista
        NodoListaC* ultimo; // puntero que indica cual es el ultimo nodo en la lista
        int tam; // entero que indica cuantos nodos tiene la lista

    protected:

    private:
};

#endif // LISTAC_H
