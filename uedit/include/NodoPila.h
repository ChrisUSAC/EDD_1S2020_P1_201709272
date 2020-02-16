#ifndef NODOPILA_H
#define NODOPILA_H

#include<iostream>

using namespace std;

class NodoPila
{
    public:

        //metodo constructor
        NodoPila(string palabraBus, string palabraRemp, bool estado, string palabra, int posicion);
        //metodo destructor
        virtual ~NodoPila();

        NodoPila* siguiente; // puntero al siguiente nodo

        //datos de la pila
        string palabraBus, palabraRemp, palabra;
        bool estado;
        int posicion;

    protected:

    private:
};

#endif // NODOPILA_H
