#include "ListaDoble.h"
int idInsercionn=0;
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
void ListaDoble::insertarInicio(char c,string id)
{
    //se instancia el nodo
    NodoListaDoble *n = new NodoListaDoble(c,id);

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

    }
    //si ya existe algun nodo
    else
    {
        if(ultimo!=primero)
        {
            ultimo = ultimo->ant;
            ultimo->sig = 0;
            tam--;
        }
        else
        {
            ultimo=primero=0;
            tam--;
        }

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
//------------------------------------------------------------------------------------------------------
void ListaDoble::insertarFinal(char c,string id)
{
    //se instancia el nodo
    NodoListaDoble *n = new NodoListaDoble(c,id);

    //se evalua si la lista aun no tiene nodos
    if(estaVacia())
    {
    /*de ser el primer nodo a ingresar se apuntan primero y ultimo a
    dicho nodo */
    primero = n;
    ultimo = n;
    tam++; // aumenta el tamano de la lista
    }
    //si ya existe algun nodo
    else
    {
        n->ant = ultimo; // puntero anterior del nodo se apunta a ultimo
        ultimo->sig = n;
        ultimo = n; // se pone la referencia del ultimo en el nuevo nodo
        tam++; // aumenta el tamano de la lista
    }
}
//------------------------------------------------------------------------------------------------------
void ListaDoble::graficar()
{
    if(this->primero!=0)
    {
       escribir();
    }
    else
    {
    cout<<"Error lista vacia no se puede graficar"<<endl;
    }

}
//------------------------------------------------------------------------------------------------------
void ListaDoble::escribir()
{
    ofstream archivo;

    archivo.open("ReporteListaDoble.dot",ios::out); // abriendo o creando el archivo

    //validar que se creara correctamente
    if(archivo.fail())
    {
            cout<<"no se pudo abrir el archivo"<<endl;

    }
    else
    {
        //escribir sintaxis dot para la imagen
            archivo<<"digraph G{ \n";
            archivo<<"rankdir=LR \n";
            archivo<<"node[ shape = box] \n";

            NodoListaDoble* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\"" + aux->c + "\"" + " width=2.0 ];" + " \n";
                aux = aux->sig;
                id++;
            }

            int id2=0;
            NodoListaDoble* aux2 = this->primero;
            while(aux2->sig != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +"[dir = back];"+" \n";
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->sig;
                id2++;
            }

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReporteListaDoble.dot -o ReporteListaDoble.png"); //Create
             system("ReporteListaDoble.png"); //Open
}
//------------------------------------------------------------------------------------------------------
void ListaDoble::buscarRemplazar(string buscada, string remplazar)
{
    string unirChars="";
    int contarCaracteres = 0;
    int contarPosicion = 0;

    NodoListaDoble* aux = this->primero;

    //recorres toda la lista
    while(aux!=0)
    {
        if(aux->c!=' ')
        {
            unirChars += aux->c;
            contarCaracteres++;

            //evaluar si es la misma palabra, si no es la ultima
            if(aux->sig!=0)
            {
                //evaluamos si es palabra completa, debe tener espacio en el aux->sig
                if(unirChars==buscada && aux->sig->c==' ')
                {
                    //eliminar la palabra en la lista e insertar el remplazo, valida que no sea el primero o el ultimo de la lista el eliminado
                    NodoListaDoble* aux2 = aux;
                    int auxContarCaracteres = contarCaracteres;
                    while(auxContarCaracteres!=0)
                    {

                        aux2->ant->sig = aux2->sig;
                        aux2->sig->ant = aux2->ant;
                        //unir anterior con el siguiente
                        aux2 = aux2->ant;
                        auxContarCaracteres--;
                    }
                    //insertar la palabra a remplazar desde la pasicion de aux2
                    for(int i = 0; i<remplazar.length();i ++)
                    {

                        //creacion del nuevo nodo
                        NodoListaDoble* r = new NodoListaDoble(remplazar[i],"a"+to_string(idInsercionn));
                        r->sig = aux2->sig;
                        r->ant =aux2;
                        aux2->sig->ant = r;
                        aux2->sig = r;
                        aux2 = aux2->sig;

                        tam++; // aumenta el tamano de la lista
                    }

                }

            }
            //aqui evaluar la ultima palabra
            else
            {
                //es la ultima palabra
                if(unirChars==buscada)
                {
                    int auxContarCaracteres = contarCaracteres;
                    //while que elimina al final de lista
                    while(auxContarCaracteres!=0)
                    {
                        EliminarUltimo();
                        auxContarCaracteres--;
                    }
                    //insertar al final caracter a caracter
                    for(int i = 0; i<remplazar.length();i ++)
                    {
                        insertarFinal(remplazar[i],"a"+to_string(idInsercionn));
                    }
                }
            }
        }
        else
        {
            //resetear cuando encuentre espacio en blanco
            unirChars = "";
            contarCaracteres = 0;
        }

        aux = aux->sig;
        contarPosicion++;
    }
}
//------------------------------------------------------------------------------------------------------
void ListaDoble::resetear()
{
    this->primero = this->ultimo = 0;
    this->tam  = 0;
}
