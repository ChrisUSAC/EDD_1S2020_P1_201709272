#include "Pila.h"

//------------------------------------------------------------------------------------------------------
//metodo constructor
Pila::Pila()
{
    this->cima=0;
    this->tamano=0;
}
//------------------------------------------------------------------------------------------------------
//metodo destructor
Pila::~Pila()
{

}
//------------------------------------------------------------------------------------------------------
void Pila::push(string palabraBus, string palabraRemp, bool estado, string palabra, int posicion)
{
    //creacion del nodo a insertar
    NodoPila *n = new NodoPila(palabraBus,palabraRemp,estado,palabra,posicion);
    //si la cima es nula
    if(cima==0)
    {
        this->cima = n;
    }
    else
    {
        n->siguiente = cima;
        this->cima = n;
    }
    this->tamano++; // se aumenta el tamano de la pila
}
//------------------------------------------------------------------------------------------------------
void Pila::pop()
{
    //evaluar si la pila no esta vacia
    if(this->cima!=0)
    {
        //se crea un temporal para no perder la referencia
        NodoPila* aux = this->cima; // por si necesito el dato eliminado
        this->cima=cima->siguiente;
        this->tamano--; // se reduce el tamano de la pila, ya que se elimino

    }
    else
    {
        cout<<"La pila esta vacia"<<endl;
    }
}
//------------------------------------------------------------------------------------------------------
void Pila::imprimir()
{
    //verificar si esta vacia
    if(this->cima==0)
    {
        cout<<"Esta vacia, no se puede imprimir"<<endl;
    }
    else
    {
        //creacion de nodo auxiliar para recorrer y no perder referencia de la cima
        NodoPila* aux = this->cima;

        //imprimir mientras tenga elementos la pila
        while(aux!=0)
        {
            cout<<"Dato: "<<aux->palabraBus<<endl;
            aux=aux->siguiente;
        }
    }
}
//------------------------------------------------------------------------------------------------------
void Pila::graficar()
{

}
//------------------------------------------------------------------------------------------------------
void Pila::escribir()
{

}
//------------------------------------------------------------------------------------------------------
