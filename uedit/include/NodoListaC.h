#ifndef NODOLISTAC_H
#define NODOLISTAC_H
#include <iostream>
using namespace std;

class NodoListaC
{
    public:
        NodoListaC(string direccion,string nombre);
        virtual ~NodoListaC();
        NodoListaC *sig; //puntero que hace referencia al siguiente nodo

        string direccion,nombre;
    protected:

    private:
};

#endif // NODOLISTAC_H
