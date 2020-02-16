#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H
#include <iostream>

using namespace std;

class NodoListaDoble
{
    public:
        NodoListaDoble(char c); //metodo constructor del nodo
        virtual ~NodoListaDoble();  //metodo destructor
        char c; //caracter a guardar

        //punteros del nodo siguiente y anterior
        NodoListaDoble *sig; //puntero siguiente del nodo
        NodoListaDoble *ant;  // puntero anterior del nodo

    protected:

    private:
};

#endif // NODOLISTADOBLE_H
