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
void Pila::push(string palabraBus, string palabraRemp, string estado, string palabra, int posicion)
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
NodoPila* Pila::pop()
{
    //evaluar si la pila no esta vacia
    //se crea un temporal para no perder la referencia
    NodoPila* aux = this->cima; // por si necesito el dato eliminado
    if(this->cima!=0)
    {
        //se crea un temporal para no perder la referencia
        NodoPila* aux = this->cima; // por si necesito el dato eliminado
        this->cima=cima->siguiente;
        this->tamano--; // se reduce el tamano de la pila, ya que se elimino
        return aux;
    }
    else
    {
        return aux;
    }
}
//------------------------------------------------------------------------------------------------------
void Pila::imprimir()
{
    //verificar si esta vacia
    if(this->cima==0)
    {
        //cout<<"Esta vacia, no se puede imprimir"<<endl;
    }
    else
    {
        //creacion de nodo auxiliar para recorrer y no perder referencia de la cima
        NodoPila* aux = this->cima;

        //imprimir mientras tenga elementos la pila
        while(aux!=0)
        {
            //cout<<"Dato: "<<aux->palabraBus<<endl;
            aux=aux->siguiente;
        }
    }
}
//------------------------------------------------------------------------------------------------------
void Pila::graficar()
{
    if(this->cima!=0)
    {
       escribir();
    }
    else
    {
    //cout<<"Error pila vacia no se puede graficar :( "<<endl;
    }
}
//------------------------------------------------------------------------------------------------------
void Pila::escribir()
{
    ofstream archivo;

    archivo.open("PilaNoRevertidos.dot",ios::out); // abriendo o creando el archivo

    //validar que se creara correctamente
    if(archivo.fail())
    {
            //cout<<"no se pudo abrir el archivo"<<endl;

    }
    else
    {

        //escribir sintaxis dot para la imagen
            archivo<<"digraph p{ \n";
            archivo<<"rankdir=LR \n";
            archivo<<"node[ shape = box] \n";


        //verificar si esta vacia
        if(this->cima==0)
        {
        //cout<<"Esta vacia, no se puede imprimir"<<endl;
        }
        else
        {
            //creacion de nodo auxiliar para recorrer y no perder referencia de la cima
            NodoPila* aux = this->cima;

            //imprimir mientras tenga elementos la pila
            int id=0;
            while(aux!=0)
            {
                if(aux==cima)
                {
                    string identificadorr = std::to_string(id);
                    archivo<<identificadorr+"[label = " + "\""
                     +"Palabra Buscada "+ aux->palabraRemp+"\n" // aux->palabraBus
                     +"Remplazada Por "+aux->palabraBus+"\n"
                     +"Estado "+aux->estado+"\n"
                     +"Palabra "+aux->palabra+"\n"
                     +"Posicion "+to_string(aux->posicion)+"\n"
                     +"\"" + " width=2.0, fillcolor = lightskyblue, style = filled ];" + " \n";
                }
                else
                {
                    string identificadorr = std::to_string(id);
                    archivo<<identificadorr+"[label = " + "\""
                     +"Palabra Buscada "+ aux->palabraRemp+"\n"
                     +"Remplazada Por "+aux->palabraBus+"\n"
                     +"Estado "+aux->estado+"\n"
                     +"Palabra "+aux->palabra+"\n"
                     +"Posicion "+to_string(aux->posicion)+"\n"
                     + "\"" + " width=2.0 ];" + " \n";

                }
                id++;
                aux=aux->siguiente;
            }

            int id2=0;
            NodoPila* aux2 = this->cima;
            while(aux2->siguiente != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->siguiente;
                id2++;
            }

        }



            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng PilaNoRevertidos.dot -o PilaNoRevertidos.png"); //Create
             system("PilaNoRevertidos.png"); //Open
}
//------------------------------------------------------------------------------------------------------
void Pila::graficar2()
{
    if(this->cima!=0)
    {
       escribir2();
    }
    else
    {
    //cout<<"Error pila vacia no se puede graficar :( "<<endl;
    }
}
//------------------------------------------------------------------------------------------------------
void Pila::escribir2()
{
    ofstream archivo;

    archivo.open("PilaRevertidos.dot",ios::out); // abriendo o creando el archivo

    //validar que se creara correctamente
    if(archivo.fail())
    {
            //cout<<"no se pudo abrir el archivo"<<endl;

    }
    else
    {

        //escribir sintaxis dot para la imagen
            archivo<<"digraph p{ \n";
            archivo<<"rankdir=LR \n";
            archivo<<"node[ shape = box] \n";


        //verificar si esta vacia
        if(this->cima==0)
        {
        //cout<<"Esta vacia, no se puede imprimir"<<endl;
        }
        else
        {
            //creacion de nodo auxiliar para recorrer y no perder referencia de la cima
            NodoPila* aux = this->cima;

            //imprimir mientras tenga elementos la pila
            int id=0;
            while(aux!=0)
            {
                if(aux==cima)
                {
                    string identificadorr = std::to_string(id);
                    archivo<<identificadorr+"[label = " + "\""
                     +"Palabra Buscada "+ aux->palabraRemp+"\n"//aux->palabraBus
                     +"Remplazada Por "+aux->palabraBus+"\n"
                     +"Estado "+aux->estado+"\n"
                     +"Palabra "+aux->palabra+"\n"
                     +"Posicion "+to_string(aux->posicion)+"\n"
                     +"\"" + " width=2.0, fillcolor = red, style = filled ];" + " \n";
                }
                else
                {
                    string identificadorr = std::to_string(id);
                    archivo<<identificadorr+"[label = " + "\""
                     +"Palabra Buscada "+ aux->palabraRemp+"\n"
                     +"Remplazada Por "+aux->palabraBus+"\n"
                     +"Estado "+aux->estado+"\n"
                     +"Palabra "+aux->palabra+"\n"
                     +"Posicion "+to_string(aux->posicion)+"\n"
                     + "\"" + " width=2.0 ];" + " \n";

                }
                id++;
                aux=aux->siguiente;
            }

            int id2=0;
            NodoPila* aux2 = this->cima;
            while(aux2->siguiente != 0 )
            {
                string identificadorr = std::to_string(id2);
                string identificadorr2 = std::to_string(id2+1);
                archivo<<identificadorr+" -> "+ identificadorr2 +" \n";
                aux2 = aux2->siguiente;
                id2++;
            }

        }



            archivo<<"}";

    }
    archivo.close();//se cierra el archivo
    system("dot -Tpng PilaRevertidos.dot -o PilaRevertidos.png"); //Create
             system("PilaRevertidos.png"); //Open
}
//------------------------------------------------------------------------------------------------------
void Pila::resetear()
{
    this->cima=0;
    this->tamano=0;
}
//------------------------------------------------------------------------------------------------------
