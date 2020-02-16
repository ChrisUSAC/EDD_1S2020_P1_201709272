#include "ListaDoble.h"
//------------------------------------------------------------------------------------------------------
//metodo constructor
ListaDoble::ListaDoble()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam  = 0;
}

//------------------------------------------------------------------------------------------------------
//metodo destructor
ListaDoble::~ListaDoble()
{
    //dtor
}
//------------------------------------------------------------------------------------------------------
//metodo booleano que inidica si la lista esta vacia
bool ListaDoble::estaVacia()
{
    return this->primero == 0;
}
//------------------------------------------------------------------------------------------------------
//metodo que inserta al inicio de la lista
void ListaDoble::insertarInicio(char c)
{
    //se instancia el nodo
    NodoListaDoble *n = new NodoListaDoble(c);

    //se evalua si la lista aun no tiene nodos
    if(estaVacia())
    {
    /*de ser el primer nodo a ingresar se apuntan primero y ultimo a
    dicho nodo */
    primero = n;
    ultimo = n;
    }
    //si ya existe algun nodo
    else
    {
        n->sig = primero; // puntero siguiente del nodo se apunta a primero
        primero->ant = n;
        primero = n; // se pone la referencia del primero en el nuevo nodo
    }
    tam++; // aumenta el tamano de la lista
}
//------------------------------------------------------------------------------------------------------
void ListaDoble::imprimir()
{
    NodoListaDoble *aux = this->primero;

    if(estaVacia())
    {
        cout<<"la lista esta vacia"<<endl;
    }
    else
    {
        while(aux!=0)
        {
            cout<<aux->c<<endl;
            aux = aux->sig;
        }
    }


}
//------------------------------------------------------------------------------------------------------
void ListaDoble::EliminarUltimo()
{
    //se evalua si la lista aun no tiene nodos
    if(estaVacia())
    {
        cout<<"La lista se encuentra vacia"<<endl;
    }
    //si ya existe algun nodo
    else
    {
        ultimo = ultimo->ant;
        ultimo->sig = 0;
        tam--;
    }
}
//------------------------------------------------------------------------------------------------------
//validar si auxiliar sale como null, quiere decir que no encontro la coincidencia
NodoListaDoble* ListaDoble::Buscar(string s)
{
    NodoListaDoble *aux = this->primero;

    while(aux!=0)
    {
        char nodo = aux->c;
        char caracter = s[0];
        if(nodo==caracter)
        {
            return aux;

        }

        aux = aux->sig;
    }

    return aux;
}
