#ifndef PILA_H
#define PILA_H
#include "NodoPila.h" // importacion del NodoPila
#include<iostream>
#include<fstream>

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        void push(string palabraBus, string palabraRemp, string estado, string palabra, int posicion); // metodo que inserta en la pila
        NodoPila* pop(); // metodo que elimina de la pila
        void imprimir(); // metodo para imprimir en consola

        //atributos de la pila
        NodoPila *cima; // puntero que hace referencia a la cima de la pila
        int tamano; // nos dira el tamaño de la pila

        void graficar(); // metodos para el graphiz
        void escribir();

        void graficar2(); //para graficar la otra pila
        void escribir2();

        void resetear(); //resetea la pila

    protected:

    private:
};

#endif // PILA_H
