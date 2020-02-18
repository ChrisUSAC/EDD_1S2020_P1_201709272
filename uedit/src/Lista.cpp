#include "Lista.h"

//------------------------------------------------------------------------------------------------------
//metodo constructor
Lista::Lista()
{
    this->primero=0;
    this->ultimo=0;
    this->tam=0;
}
//------------------------------------------------------------------------------------------------------
//destructor
Lista::~Lista()
{

}
//------------------------------------------------------------------------------------------------------
bool Lista::estaVacia()
{
    //si no contiene elementos retorna un true
    return this->primero==0;
}
//------------------------------------------------------------------------------------------------------
//insertar ordenadamente en la lista
void Lista::insertar(string palabraBus, string palabraRemp)
{
{
    //creacion del nodo a insertar
    NodoLista* n = new NodoLista(palabraBus,palabraRemp);

    //evaluar si esta vacia la lista
    if(estaVacia())
    {
        //se le iguala el primero y el ultimo
        this->primero = n;
        this->ultimo = n;
        this->tam++;
        //cout<<"no existia nada e inserto al inico"<<endl;
    }
    else
    {
        int indice = 0;
        NodoLista* prim = this->primero;
        //cout<<"buscara indice "<<indice<<endl;
        indice = encontrarIndice(palabraBus,prim);
        //cout<<"el indice encontrado fue: "<<indice<<endl;

        //es una insercion al inicio
        if(indice==0)
        {
            n->siguiente = this->primero;
            this->primero = n;
            this->tam++;
            //cout<<"insertar al inicio"<<endl;
            return;
        }
        //es una insercion al final
        if(indice == this->tam)
        {
            this->ultimo->siguiente = n;
            this->ultimo = n;
            this->tam++;
            //cout<<"insercion al final///////////"<<tam-1<<endl;
            return;
        }
        //insercion en medio
        if(indice!=0 && indice!=this->tam)
        {
        //cout<<"entro a insertar en medio "<<endl;
        //cout<<"tiene indice: "<<indice<<endl;
        n = insertarAt(indice,n);
        this->tam++;

        }

    }

}
}
//------------------------------------------------------------------------------------------------------
//metodo para insercion entre dos nodos
NodoLista* Lista::insertarAt(int indice, NodoLista* nue)
{
    //creacion de nodos auxiliares para no perder la referencia de la lista
    NodoLista* aux1 = this->primero;
    NodoLista* aux2= this->primero;
    //contador que dira donde termina el while
    int contador =0;
    int contador2 =0;

    while(contador!=indice)
    {
        contador++;
        //aux1 guarda el primero

        aux1 = aux1->siguiente;

    }


    while(contador2!=indice-1)
    {
        contador2++;
        //aux1 guarda el primero

        aux2 = aux2->siguiente;

    }
    aux2->siguiente = nue;
    nue->siguiente = aux1;

    return nue;
}
//------------------------------------------------------------------------------------------------------
void Lista::imprimir()
{

    NodoLista* auxil=this->primero;

    if(estaVacia())
    {
        //cout<<"Lista Vacia"<<endl;
    }
    else
    {
        while(true)
        {

        if(auxil == this->ultimo)
        {
            break;
        }
        else
        {
            auxil = auxil->siguiente;
        }
        }

    }

}
//------------------------------------------------------------------------------------------------------
//metodo que retorna el indice donde se insertara en nuevo nodo
int Lista::encontrarIndice(string palabraBus,NodoLista* prim)
{
    //indice a retornar
    int indice=0;
    //se posiciona un auxiliar al inicio de la lista
    NodoLista* aux = this->primero;

    //ciclo que posicionara el indice en el lugar a insertar
    while(aux!=0)
    {
        //cout<<"entro al while de buscar indice "<<indice<<endl;
        const char *a = aux->palabraBus.c_str();
        const char *b = palabraBus.c_str();
        if(strcmp(b,a) == 1)
        {
            indice++;

        }
        aux = aux->siguiente;

    }
    //cout<<"este es el indice que retorna el metodo: "<<indice<<endl;
    return indice;
}
//------------------------------------------------------------------------------------------------------
void Lista::graficar()
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
void Lista::escribir()
{
    ofstream archivo;

    archivo.open("ReportePalabrasBuscadas.dot",ios::out); // abriendo o creando el archivo

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

            NodoLista* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\""
                + aux->palabraBus+"\n"
                + "Remplazada por: "
                +aux->palabraRemp
                + "\"" + " width=2.0 , fillcolor=red ,style = filled];" + " \n";
                aux = aux->siguiente;
                id++;
            }

            int id2=0;
            NodoLista* aux2 = this->primero;
            while(aux2->siguiente != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->siguiente;
                id2++;
            }

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReportePalabrasBuscadas.dot -o ReportePalabrasBuscadas.png"); //Create
             system("ReportePalabrasBuscadas.png"); //Open

}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
void Lista::graficar2()
{
    if(this->primero!=0)
    {
       escribir2();
    }
    else
    {
    //cout<<"Error lista vacia no se puede graficar :( "<<endl;
    }
}
//------------------------------------------------------------------------------------------------------
void Lista::escribir2()
{
    ofstream archivo;

    archivo.open("ReportePalabrasRemplazadas.dot",ios::out); // abriendo o creando el archivo

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

            NodoLista* aux = this->primero;

            int id=0;
            while(aux != 0 )
            {
                string identificadorr = std::to_string(id);
                archivo<<identificadorr+"[label = " + "\""
                + aux->palabraBus+"\n"
                + "Remplazado a: "
                +aux->palabraRemp
                + "\"" + " width=2.0 , fillcolor=green ,style = filled];" + " \n";
                aux = aux->siguiente;
                id++;
            }

            int id2=0;
            NodoLista* aux2 = this->primero;
            while(aux2->siguiente != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->siguiente;
                id2++;
            }

            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng ReportePalabrasRemplazadas.dot -o ReportePalabrasRemplazadas.png"); //Create
             system("ReportePalabrasRemplazadas.png"); //Open

}
//------------------------------------------------------------------------------------------------------
