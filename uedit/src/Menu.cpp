#include "Menu.h"
#include "cursor.h"


//Declaracion de la lista que tiene a los caracteres de la aplicacion
static ListaDoble* ListaCaracteres = new ListaDoble();
Pila* CambiosRealizados = new Pila();
Pila* CambiosRevertidos = new Pila();
static int idInsercion = 0;

//---------------------------------------------------------------------------------------------
//metodo constructor
Menu::Menu()
{
    //ctor
}
//---------------------------------------------------------------------------------------------
//metodo destructor
Menu::~Menu()
{
    //dtor
}
//---------------------------------------------------------------------------------------------
void Menu::menuPrincipal()
{
    initscr(); //inicio de curses
    noecho();
    cbreak();

    int alto,ancho,pos_x,pos_y; //variables para la creacion de la ventana
    alto = 20;
    ancho = 60;
    pos_x = pos_y = 0;

    WINDOW* win = newwin(alto,ancho,pos_y,pos_x); // instancia de una ventana
    box(win,0,0);
    refresh();
    wrefresh(win);

    //permite el uso de las flechas del teclado
    keypad(win,true);

    string eleccion[4] = {"1. CREAR ARCHIVO" ,"2. ABRIR ARCHIVO","3. ARCHIVOS RECIENTES","4. SALIR"}; // para la seleccion del menu
    int choice=0;
    int remarcar = 0;

    mvwprintw(win,3,5,"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA");
    mvwprintw(win,4,5,"FACULTAD DE INGENIERIA");
    mvwprintw(win,5,5,"ESTRUCTURA DE DATOS");
    mvwprintw(win,6,5,"PRACTICA 1");
    mvwprintw(win,7,5,"CHRISTOPHER ALEXANDER COBAR ASTURIAS");
    mvwprintw(win,8,5,"201709272");
    mvwprintw(win,12,5,"MENU ");

    while(1)
    {
        int lugarY = 13;
        for(int i = 0; i < 4;i++)
        {
            if(i==remarcar)


                wattron(win,A_REVERSE);
            mvwprintw(win,lugarY++,5,eleccion[i].c_str());
            wrefresh(win);
            wattroff(win,A_REVERSE);

        }
        choice = wgetch(win);

        switch(choice)
        {
        case KEY_UP:
            remarcar--;
            break;
        case KEY_DOWN:
            remarcar++;
            break;
        default:
            break;
        }


        if(choice == 10) // si se presiona tecla enter, sale del while
        {
            break;
        }

        if(remarcar == 4) // remarca la opcion 1
        {
            remarcar = 0;

        }
        if(remarcar == -1) //remarca la opcion 4
        {
            remarcar = 3;

        }

    }

    endwin(); // destruye la ventana del menuPrincipal y abre la ventana del siguiente menu

    //evaluar que opcion del menu se desea utilizar
    if(remarcar==0)
    {
        //desplegar el editor de texto
        menuEditor();
    }
    else if(remarcar==1)
    {
        //desplegar menu abrir archivos

    }
    else if(remarcar==2)
    {
        //desplegar menu archivos recientes

    }
    else if(remarcar==3)
    {
        //finalizar aplicacion
    }

}
//---------------------------------------------------------------------------------------------
void Menu::menuEditor()
{
    initscr(); //inicio de curses
    noecho();
    cbreak();

    int alto,ancho,pos_x,pos_y; //variables para la creacion de la ventana
    int yMax,xMax;
    yMax = 40;
    xMax = 100;
    alto = yMax;
    ancho = xMax;
    pos_x = pos_y = 0;

    WINDOW* win = newwin(alto,ancho,pos_y,pos_x); // instancia de una ventana
    box(win,0,0);
    refresh();


    mvwprintw(win,39,4,"^w (Buscar y Remplazar)");
    mvwprintw(win,39,38,"^c Reportes");
    mvwprintw(win,39,58,"^s Guardar");
    wrefresh(win);

    //creacion del cursor
    cursor * p = new cursor(win,1,1,'f');

    //ciclo para la escritura en el editor
    while(true)
    {
        int tecla = p->getmv(); //caracter a evaluar y proceder a imprimirlo
        char intTecla = tecla;

        if(tecla==27) //tecla de escape, sale del editor y regresa al menuPrincipal
        {
            ListaCaracteres->resetear();
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            menuPrincipal();
            break;
        }

        //evaluar si se utilizo el borrar
        else if(tecla==8)
        {
            //se debe eliminar el ultimo caracter ingresado a la lista

            p->settCaracter(' '); // simular borrado con un caracter de espacio

            p->mvizq();
            p->display();
            ListaCaracteres->EliminarUltimo();
            //wrefresh(win);

        }

        //evaluar si se presiona enter
        else if(tecla==10)
        {
            p->settyLoc(p->getyLoc()+1);
            p->settxLoc(1);
            ListaCaracteres->insertarFinal(p->getCaracter(),to_string(idInsercion++));
        }
        else if(tecla==3) //ctrl+c funcion de reportes
        {
            metodoReportes(win,p);
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            //abrir la ventana con los caracteres de la lista y los remplazos
            repintarEditor();
        }
        else if(tecla==23) //ctrl+w funcion buscar y remplazar
        {
            metodoBuscarRemplazar(win,p);
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            //abrir la ventana con los caracteres de la lista y los remplazos
            repintarEditor();

        }
        else if(tecla==19) //ctrl+s  funcion de guardado
        {

        }
        else if(tecla==24) //ctrl+x  funcion de escape
        {
            ListaCaracteres->resetear();
            CambiosRealizados->resetear();
            CambiosRevertidos->resetear();
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            menuPrincipal();
            break;
        }
        else if(tecla==26) //ctrl+z  revertir un cambio
        {
            NodoPila* aux = CambiosRealizados->pop();
            if(aux!=0)
            {

                bool comfirmar = ListaCaracteres->buscarRemplazarPila(aux->palabraRemp,aux->palabraBus);
                if(comfirmar)
                {
                    CambiosRevertidos->push(aux->palabraBus,aux->palabraRemp,"Revertido","NULL",0);
                }
                ListaCaracteres->graficar();
                CambiosRevertidos->graficar2();
            }
            endwin(); // destruye la ventana
            //abrir la ventana con los caracteres de la lista y los remplazos
            clear();
            repintarEditor();

        }
        else if(tecla==25) //ctrl+y restablecer un cambio
        {
            NodoPila* aux = CambiosRevertidos->pop();
            if(aux!=0)
            {

                bool comfirmar = ListaCaracteres->buscarRemplazarPila(aux->palabraBus,aux->palabraRemp);
                if(comfirmar)
                {
                    CambiosRealizados->push(aux->palabraBus,aux->palabraRemp,"NO Revertido","NULL",0);
                }
                else
                {
                    if(aux->palabraRemp=="")
                    {
                        CambiosRevertidos->push(aux->palabraBus,aux->palabraRemp,"NO Revertido","NULL",0);
                    }

                }
                ListaCaracteres->graficar();
                CambiosRealizados->graficar();
            }
            endwin(); // destruye la ventana
            //abrir la ventana con los caracteres de la lista y los remplazos
            clear();
            repintarEditor();

        }
        else
        {   //imprimimos el caracter
            p->display();
            //evaluamos si se termino la linea
            if(p->getxLoc()!=p->getxMax())
            {
                p->mvder();
            }
            ListaCaracteres->insertarFinal(p->getCaracter(),to_string(idInsercion++));

        }

        wrefresh(win);
    }

    endwin(); // destruye la ventana del menueditor

}
//---------------------------------------------------------------------------------------------
void Menu::metodoBuscarRemplazar(WINDOW* win,cursor* p)
{
    string parametro,buscar,remplazar;
    parametro=buscar=remplazar="";
    string delimitador = ";";

    mvwprintw(win,38,4,"Buscar y Remplazar:");
    p->settxLoc(23);
    p->settyLoc(38);
    wrefresh(win);

    while(true)
    {
        int tecla =wgetch(win); // optiene el caracter presionado en teclado
        char intTecla = tecla;

        parametro+=intTecla; // concatenacion de chars para cuando se presione enter, hacer split y evaluar
        if(tecla==10) //si presiona enter ejecutar el metod
        {

            buscar = parametro.substr(0, parametro.find(delimitador)); //subcadena hasta antes de ;
            parametro.erase(0, parametro.find(delimitador) + delimitador.length()); //borra hasta el ;
            remplazar = parametro;
            break;
        }
        else if(tecla==24) //si presiona ctrl+x cancelar ejecucion del metodo
        {
            break;
        }
        p->settCaracter(intTecla); // asignacion para que se vea en pantalla
        p->display();//imprimimos el caracter

        if(p->getxLoc()!=p->getxMax())//evaluamos si se termino la linea
        {
            p->mvder();
        }

        wrefresh(win);
    }
    CambiosRealizados->push(buscar,remplazar,"No Revertido","NULL",0); //push a la pila de cambios realizados
    ListaCaracteres->buscarRemplazar(buscar,remplazar); //llamada al metodo buscar y remplazar
    ListaCaracteres->graficar();
}
//---------------------------------------------------------------------------------------------
void Menu::repintarEditor()
{
    initscr(); //inicio de curses
    noecho();
    cbreak();

    int alto,ancho,pos_x,pos_y; //variables para la creacion de la ventana
    int yMax,xMax;
    bool unaVez = true; // repintar solo una vez lo que esta en la lista
    yMax = 40;
    xMax = 100;
    alto = yMax;
    ancho = xMax;
    pos_x = pos_y = 0;

    WINDOW* win = newwin(alto,ancho,pos_y,pos_x); // instancia de una ventana
    box(win,0,0);
    refresh();


    mvwprintw(win,39,4,"^w (Buscar y Remplazar)");
    mvwprintw(win,39,38,"^c Reportes");
    mvwprintw(win,39,58,"^s Guardar");
    wrefresh(win);

    //creacion del cursor
    cursor * p = new cursor(win,1,1,'f');




    //ciclo para la escritura en el editor
    while(true)
    {
    //actualizar lo ya escrito
    if(!ListaCaracteres->estaVacia() && unaVez)
    {

    NodoListaDoble *pintar = ListaCaracteres->primero;
    while(pintar!=0)
    {
        p->settCaracter(pintar->c);
        //imprimimos el caracter
        p->display();
        //evaluamos si se termino la linea
        if(p->getxLoc()!=p->getxMax())
        {
            p->mvder();
        }

        pintar = pintar->sig;
        wrefresh(win);
    }
        unaVez = false;
    }

        int tecla = p->getmv(); //caracter a evaluar y proceder a imprimirlo
        char intTecla = tecla;

        if(tecla==27) //tecla de escape, sale del editor y regresa al menuPrincipal
        {
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            menuPrincipal();
            break;
        }

        //evaluar si se utilizo el borrar
        else if(tecla==8)
        {
            //se debe eliminar el ultimo caracter ingresado a la lista

            p->settCaracter(' '); // simular borrado con un caracter de espacio
            p->mvizq();
            p->display();
            ListaCaracteres->EliminarUltimo();

        }

        //evaluar si se presiona enter
        else if(tecla==10)
        {
            p->settyLoc(p->getyLoc()+1);
            p->settxLoc(1);
            ListaCaracteres->insertarFinal(p->getCaracter(),to_string(idInsercion++));
        }
        else if(tecla==3) //ctrl+c funcion de reportes
        {
            metodoReportes(win,p);
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            //abrir la ventana con los caracteres de la lista y los remplazos
            repintarEditor();
        }
        else if(tecla==23) //ctrl+w funcion buscar y remplazar
        {
            metodoBuscarRemplazar(win,p);
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            //abrir la ventana con los caracteres de la lista y los remplazos
            repintarEditor();

        }
        else if(tecla==19) //ctrl+s  funcion de guardado
        {

        }
        else if(tecla==24) //ctrl+x  funcion de escape
        {
            ListaCaracteres->resetear();
            CambiosRealizados->resetear();
            CambiosRevertidos->resetear();
            endwin(); // destruye la ventana
            clear(); // limpia la pantalla y muestra el menu principal nuevamente
            menuPrincipal();
            break;
        }
        else if(tecla==26) //ctrl+z  revertir un cambio
        {
            NodoPila* aux = CambiosRealizados->pop();
            if(aux!=0)
            {

                bool comfirmar = ListaCaracteres->buscarRemplazarPila(aux->palabraRemp,aux->palabraBus);
                if(comfirmar)
                {
                    CambiosRevertidos->push(aux->palabraBus,aux->palabraRemp,"Revertido","NULL",0);
                }
                ListaCaracteres->graficar();
                CambiosRevertidos->graficar2();
            }
            endwin(); // destruye la ventana
            //abrir la ventana con los caracteres de la lista y los remplazos
            clear();
            repintarEditor();

        }
        else if(tecla==25) //ctrl+y restablecer un cambio
        {
            NodoPila* aux = CambiosRevertidos->pop();
            if(aux!=0)
            {

                bool comfirmar = ListaCaracteres->buscarRemplazarPila(aux->palabraBus,aux->palabraRemp);
                if(comfirmar)
                {
                    CambiosRealizados->push(aux->palabraBus,aux->palabraRemp,"NO Revertido","NULL",0);
                }
                else
                {
                    if(aux->palabraRemp=="")
                    {
                        CambiosRevertidos->push(aux->palabraBus,aux->palabraRemp,"NO Revertido","NULL",0);
                    }

                }
                ListaCaracteres->graficar();
                CambiosRealizados->graficar();
            }
            endwin(); // destruye la ventana
            //abrir la ventana con los caracteres de la lista y los remplazos
            clear();
            repintarEditor();

        }
        else
        {   //imprimimos el caracter
            p->display();
            //evaluamos si se termino la linea
            if(p->getxLoc()!=p->getxMax())
            {
                p->mvder();
            }
            ListaCaracteres->insertarFinal(p->getCaracter(),to_string(idInsercion++));

        }

        wrefresh(win);
    }

    endwin(); // destruye la ventana del menueditor

}
//---------------------------------------------------------------------------------------------
void Menu::metodoReportes(WINDOW* win, cursor* p)
{
    mvwprintw(win,38,4,"Reportes: 1)Lista 2)Palabras Buscadas 3)Palabras Ordenadas");

    wrefresh(win);

    while(true)
    {
        int tecla =wgetch(win); // optiene el caracter presionado en teclado
        char intTecla = tecla;

        if(tecla==49) //numero 1 reporte de lista
        {
            ListaCaracteres->graficar();
        }
        if(tecla==50) //numero 2 reporte de log Cambios es decir las dos pilas
        {
            CambiosRealizados->graficar();
            CambiosRevertidos->graficar2();
        }
        if(tecla==51) //numero 3 reporte lista simple del log de cambios ordenada alfabeticamente
        {
            //instanciar dos pilas una para cada reporte
            Pila* buscadas = CambiosRealizados;

            //lista Simple enlazada que mostrara el reporte de los cambios realizados
            Lista* listaSimple = new Lista();
            Lista* listaSimple2 = new Lista();

            while(buscadas->cima!=0)
            {
                NodoPila* aux = buscadas->pop();
                listaSimple->insertar(aux->palabraBus,aux->palabraRemp);
                listaSimple2->insertar(aux->palabraRemp,aux->palabraBus);
            }

            listaSimple->graficar();
            listaSimple2->graficar2();

        }
        else if(tecla==24) //si presiona ctrl+x cancelar ejecucion del metodo
        {
            break;
        }

        wrefresh(win);
    }
}
