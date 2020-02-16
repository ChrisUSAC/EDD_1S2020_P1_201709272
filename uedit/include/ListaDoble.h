#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
#include <cstring> //biblioteca para comparar strings
#include"NodoListaDoble.h"//se incluye el nodo

using namespace std;

class ListaDoble
{
    public:
        ListaDoble(); //metodo contructor
        virtual ~ListaDoble(); //metodo destructor

        bool estaVacia(); // metodo que informa si la lista esta vacia
        void imprimir(); // metodo que imprime la lista en consola
        void EliminarUltimo(); // metodo que elimina el ultimo nodo de la lista
        NodoListaDoble* Buscar(string s); //busca el primer caracter del string en la lista
        void insertarInicio(char c); // metodo que insertara un nodo al inicio de la lista


        NodoListaDoble* primero; // puntero que indica cual es el primer nodo de la lista
        NodoListaDoble* ultimo; // puntero que indica cual es el ultimo nodo en la lista
        int tam; // entero que indica cuantos nodos tiene la lista, es decir el tamano.

    protected:

    private:
};

#endif // LISTADOBLE_H
