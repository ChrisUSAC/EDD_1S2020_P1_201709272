#include "ListaC.h"

//------------------------------------------------------------------------------------------------------
//constructor
ListaC::ListaC()
{
    this->primero = 0;
    this->ultimo = 0;
    this->tam  = 0;
}
//------------------------------------------------------------------------------------------------------
//destructor
ListaC::~ListaC()
{

}
//------------------------------------------------------------------------------------------------------
bool ListaC::estaVacia()
{
    return this->primero==0;
}
//------------------------------------------------------------------------------------------------------
//metodo para imprimir en consola la lista circula de inicio a fin
void ListaC::imprimir()
{
    if(estaVacia())
    {
       cout<<"lista vacia"<<endl;
    }
    else
    {
        //nodo temporal para no mover la referecia al primero
        NodoListaC* aux = this->primero;
        //entero que servira para iterar el while
        int indice =0;

        //ciclo de impresion en consola
        while(indice < this->tam)
        {
            cout<<indice+1<<": "<<aux->direccion<<endl;
            aux =aux->sig;
            indice++;

        }

    }
}
//------------------------------------------------------------------------------------------------------
void ListaC::insertarFinal(string direccion, string nombre)
{
    //se instancia el nodo a insertar
    NodoListaC* n = new NodoListaC(direccion,nombre);
    //es evalua si la lista esta vacia
    if(estaVacia())
    {
        //apuntar primero y ultimo al nuevo nodo
        this->primero = n;
        this->ultimo = n;
        //crear circulo
        this->ultimo->sig = n;
    }
    else
    {
        //si ya existe uno
        this->ultimo->sig = n;
        this->ultimo = n;
        this->ultimo->sig = this->primero;
    }
    //se aumenta el tamano de la lista
    this->tam++;
}

//------------------------------------------------------------------------------------------------------
void ListaC::graficar()
{
    if(this->primero!=0)
    {
       escribir();
    }
    else
    {
    //cout<<"Error lista vacia no se puede graficar :( "<<endl;
    }
}
//------------------------------------------------------------------------------------------------------
void ListaC::escribir()
{
    ofstream archivo;

    archivo.open("ReporteArchivos.dot",ios::out); // abriendo o creando el archivo

    //validar que se creara correctamente
    if(archivo.fail())
    {
            //cout<<"no se pudo abrir el archivo"<<endl;

    }
    else
    {

        //escribir sintaxis dot para la imagen
            archivo<<"digraph G{ \n";
            archivo<<"rankdir=LR \n";
            archivo<<"node[ shape = box] \n";

            NodoListaC* aux = this->primero;

            int id=0;
            int indice=0;
            while(indice < this->tam )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\""
                + aux->direccion+"\n"+ "\"" + " width=2.0 , fillcolor=red ,style = filled];" + " \n";
                aux = aux->sig;
                indice++;
                id++;
            }

            int id2=0;
            NodoListaC* aux2 = this->primero;
            while(aux2->sig != this->primero )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->sig;
                id2++;
            }
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(0);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
/*
            int id2=0;
            int indice2=0;
            NodoListaC* aux2 = this->primero;
            if(this->tam!=1)
            {
            while(indice2 != this->tam )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->sig;
                indice2++;
                id2++;
            }
                string identificadorr = std::to_string(0);
                string identificadorr2 = std::to_string(id2-1);
                archivo<<identificadorr2+" -> "+ identificadorr +" \n";

            }
            else
            {
                string identificadorr = std::to_string(0);
                archivo<<identificadorr+" -> "+ identificadorr +" \n";
            }*/

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReporteArchivos.dot -o ReporteArchivos.png"); //Create
             system("ReporteArchivos.png"); //Open

}
