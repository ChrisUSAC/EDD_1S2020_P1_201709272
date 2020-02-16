#ifndef PILA_H
#define PILA_H
#include "NodoPila.h" // importacion del NodoPila

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        void push(string palabraBus, string palabraRemp, bool estado, string palabra, int posicion); // metodo que inserta en la pila
        void pop(); // metodo que elimina de la pila
        void imprimir(); // metodo para imprimir en consola

        //atributos de la pila
        NodoPila *cima; // puntero que hace referencia a la cima de la pila
        int tamano; // nos dira el tamaño de la pila

        void graficar(); // metodos para el graphiz
        void escribir();

    protected:

    private:
};

#endif // PILA_H
