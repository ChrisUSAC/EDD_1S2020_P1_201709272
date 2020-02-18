#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H
#include <iostream>
#include <string>

using namespace std;

class NodoListaDoble
{
    public:
        NodoListaDoble(char c,string id); //metodo constructor del nodo
        virtual ~NodoListaDoble();  //metodo destructor
        char c; //caracter a guardar
        string id; // identificador de cada nodo

        //punteros del nodo siguiente y anterior
        NodoListaDoble *sig; //puntero siguiente del nodo
        NodoListaDoble *ant;  // puntero anterior del nodo

    protected:

    private:
};

#endif // NODOLISTADOBLE_H
