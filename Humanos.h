#ifndef HUMANOS_H
#define HUMANOS_H
#include <string>
#include <QtCore>
#include <bits/uniform_int_dist.h>
using namespace std ;

struct NodoHumano;
struct ListaAmigos;
struct Humano;

struct NodoHumano{
  Humano * persona;
  NodoHumano * siguiente;
  NodoHumano * anterior;
  NodoHumano(Humano * _persona){
      persona = _persona;
      siguiente= anterior = NULL;
  }

};
struct ListaHumano{
    NodoHumano * primerNodo;

    int largo;
    ListaHumano(){
        primerNodo = NULL;
        largo = 0;
    }


    void agregarHumano(Humano * nuevo){
        if (primerNodo == NULL){
            primerNodo = new NodoHumano(nuevo);
            primerNodo->siguiente= primerNodo;
            primerNodo->anterior = primerNodo;

        }
        else{
            NodoHumano * nuevoHumano = new NodoHumano(nuevo);
            nuevoHumano->siguiente = primerNodo;
            nuevoHumano->anterior = primerNodo->anterior;
            primerNodo->anterior->siguiente = nuevoHumano;
            primerNodo->anterior = nuevoHumano;

        }
        largo ++;
    }
    void init(){
        primerNodo = NULL;
        largo = 0;
    }
    void agregarAlInicio(Humano * nuevo){
        if (primerNodo == NULL){
            primerNodo = new NodoHumano(nuevo);
            primerNodo->siguiente= primerNodo;
            primerNodo->anterior = primerNodo;

        }
        else{
            NodoHumano * nuevoHumano = new NodoHumano(nuevo);
            nuevoHumano->siguiente = primerNodo;
            nuevoHumano->anterior = primerNodo->anterior;
            primerNodo->anterior->siguiente = nuevoHumano;
            primerNodo->anterior = nuevoHumano;
            primerNodo = nuevoHumano;

        }
        largo ++;
    }

    NodoHumano * centroLista (){
        NodoHumano * tmp = primerNodo;
        if (largo == 1){
            return tmp;
        }
        for (int i=0; i<largo/2; i++){
               tmp = tmp->siguiente;
            }
        return tmp;
    }

    ListaHumano * primerMitadOrden (){
        ListaHumano * newList = new ListaHumano();
        NodoHumano * tmp = primerNodo;
        while (tmp != centroLista()){
            newList->agregarHumano(tmp->persona);
            tmp = tmp->siguiente;
        }
        return newList;
    }

    ListaHumano * segundaMitad (){
        ListaHumano * newList = new ListaHumano();
        NodoHumano * tmp = centroLista()->siguiente;
        do{
            newList->agregarHumano(tmp->persona);
            tmp = tmp->siguiente;

        }while(tmp!=primerNodo);
        return newList;
    }

    ListaHumano *nodosArbol (int secuencia){
        ListaHumano * newList = new ListaHumano();

        if (primerNodo != NULL){
                NodoHumano * tmp = primerNodo;
                int cont = secuencia-1;
                do{
                    cont ++;
                    if (cont == secuencia){
                        newList->agregarHumano(tmp->persona);
                        cont = 0;
                    }
                    tmp = tmp->siguiente;
                }while(tmp!=primerNodo);
            }
       // qDebug()<<"Largo de nodos "<<newList->largo;
        return newList;
    }

    void mostrarLista ();
    void agregarPorPecados(Humano * );
    void agregarPorBuenasAcciones(Humano * );
    QString matarCincoHp(QString villano);
    QString killCincuentaPorciento(QString villano);

};
struct NodoPais{
  QString pais;
  NodoPais * siguiente;
  NodoPais * anterior;
  NodoPais(QString _pais){
      pais = _pais;
      siguiente= anterior = NULL;
  }

};
struct ListaPaises{
    NodoPais * primerNodo;
    NodoPais * ultimoNodo;
    ListaPaises(){
        primerNodo = ultimoNodo = NULL;
    }
    void agregarPais(QString nuevo){
        if (primerNodo == NULL){
            primerNodo = ultimoNodo = new NodoPais(nuevo);
        }
        else{
            ultimoNodo->siguiente = new NodoPais(nuevo);
            ultimoNodo = ultimoNodo->siguiente;
        }
    }

    //VERIFICAR
    bool VerificarPais(QString check){
        NodoPais * tmp = primerNodo;
        while(tmp != NULL){
            if (tmp->pais == check)
                return false;
           tmp = tmp->siguiente;
        }
        return true;
    }
};
struct NodoDeporte{
  QString deporte;
  NodoDeporte * siguiente;
  NodoDeporte * anterior;
  NodoDeporte(QString _deporte){
      deporte = _deporte;
      siguiente= anterior = NULL;
  }

};

struct ListaDeportes{
    int frecuencia;
    NodoDeporte * primerNodo;
    NodoDeporte * ultimoNodo;
    int largo = 0;
    ListaDeportes(){
        primerNodo = ultimoNodo = NULL;
    }
    void agregarDeportes(QString nuevo){
        if (primerNodo == NULL){
            primerNodo = ultimoNodo = new NodoDeporte(nuevo);
        }
        else{
            ultimoNodo->siguiente = new NodoDeporte(nuevo);
            ultimoNodo = ultimoNodo->siguiente;
        }
        largo++;
    }

    //VERIFICAR
    bool VerificarDeporte(QString check){
        NodoDeporte * tmp = primerNodo;
        while(tmp != NULL){
            if (tmp->deporte == check){
                return false;
            }
            tmp = tmp->siguiente;
        }
        return true;
    }

    QString imprimirDeporte(){
        NodoDeporte * tmp = primerNodo;
        QString deportes = "";
        while(tmp != NULL){
            deportes += tmp->deporte + "\n";
            tmp = tmp->siguiente;
        }
        return deportes;
    }
};


struct NodoSuceso{
  QString suceso;
  NodoSuceso * siguiente;
  NodoSuceso * anterior;
  NodoSuceso(QString _suceso){
      suceso = _suceso;
      siguiente = anterior = NULL;
  }

};

struct ListaSucesos{
    NodoSuceso * primerNodo;
    NodoSuceso * ultimoNodo;
    int largo = 0;
    ListaSucesos(){
        primerNodo = ultimoNodo = NULL;
    }
    void agregarSucesos(QString nuevo){
        if (primerNodo == NULL){
            primerNodo = ultimoNodo = new NodoSuceso(nuevo);
        }
        else{
            ultimoNodo->siguiente = new NodoSuceso(nuevo);
            ultimoNodo = ultimoNodo->siguiente;
        }
        largo++;
    }

    QString mostrarLista(){
        QString sucesos = "Sucesos: \n";
        if (primerNodo != NULL){
                NodoSuceso * tmp = primerNodo;
                do{
                    sucesos += tmp->suceso + "\n";
                    tmp = tmp->siguiente;
                }while(tmp!=NULL);
        }
        return sucesos;
    }
 };
struct Humano{
    int index;
    int ID;
    QString nombre;
    QString apellido;
    QString genero;
    QString creencia;
    QString profesion;
    bool vivo;
    //Fecha de nacimiento
    int dia;
    int mes;
    int anno;
    QString grupoEtario;
    // Etica
    int pecados[7] = {0,0,0,0,0,0,0}; // Lujuria,Gula,Avaricia,Pereza,Ira,Envidia,Soberbia
    int buenasAcciones[7] = {0,0,0,0,0,0,0};;//Castidad, Ayuno,Donación,Calma,Solidaridad,Humildad

    //Personas
    ListaHumano amigos;
    int estadoMarital;
    int edad;
    Humano * Padre;
    Humano * Madre;
    Humano * Pareja;
    int cantHijos;
    ListaHumano hijos;
    // Salud
    int cantDeporte;
    ListaDeportes deportes;
    //sucesos
    ListaSucesos sucesos;
    //Paises
    QString paisOrigen;
    QString continente;
    ListaPaises paisesVisitados;


    //CONSTRUCTOR
    Humano(){

    }
    Humano(int _index){
        index = _index;
        ID = generarID();
        genero = generarGenero();
        nombre = generarNombre();
        apellido = generarApellido();
        creencia = generarCreencia();
        profesion = generarProfresion();
        generarFecha();
        calcularGrupo();
        vivo = true;
        paisOrigen = generarPais();
        //generarExperiencias();
        generarCantHijos();
        generarDeportes();

    }
    void generarFecha();
    QString generarGenero();
    QString generarProfresion();
    QString generarCreencia();
    QString generarNombre();
    QString generarApellido();
    void calcularGrupo();
    int generarID();
    QString generarPais();
    int generarCantidadE();
    void generarExperiencias();
    QString imprimirHumano();
    QString imprimirAmigos();
    QString imprimirAmigosOtro();
    void asignarPecados();
    void asignarBuenasAcciones();
    void generarCantHijos();
    void crearAmigos(NodoHumano *);
    bool encontrarAmigosComun(NodoHumano *,NodoHumano *);
    void crearHijos(NodoHumano *);
    void crearHijosAux(NodoHumano *,NodoHumano *);
    bool encontrarParentesco(NodoHumano *,NodoHumano *);
    bool posiblePadre(NodoHumano *,NodoHumano *);
    bool alreadyIn(NodoHumano * padre,NodoHumano * hijo);
    void generarDeportes();
    bool alreadyAmigo(NodoHumano *);
    void imprimirPruebas();
    int cantPecados();
    int cantBuenasAcciones();
    QString formato (QString informacion);
    bool allFriendsDead();
    void killAmigos();

};
#endif // HUMANOS_H
