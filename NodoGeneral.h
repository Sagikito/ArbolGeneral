#pragma once 

#include <list>
#include <queue>
using namespace std;


template <typename T>
struct NodoGeneral
{
    //datos
    T dato;
    list<NodoGeneral<T>*> p_hijos; //NodoGeneral<T>* sig seria como lo haciamos en la lista, un apuntador a un dato;
    //de tipo NodoGeneral aqui es un conjunto de apuntadores a datos de tipo NodoGeneral y por eso se hace así
    
    //constructor ?????????????????????? (VER HOJITA PARA PREGUNTAR)
    NodoGeneral();
    
    //destructor ?????????????????????????????'
    ~NodoGeneral();
    
    //operaciones
    T& obtenerDato(); //?????? T&?? que significa devolver una referencia? que extraño...
    void fijarDato(T& nuevoDato);
    void limpiarLista();

    bool esHoja();
    int N_altura();
    unsigned int N_tamano();

    void agregarHijo(T& Dato); 
    bool eliminarHijo(T& Dato);

    bool N_insertarNodo(T datoPadre, T nuevoDato);
    bool N_eliminarNodo(T datox);
    bool N_buscarNodo(T datob);

    void N_preOrden();
    void N_posOrden();
    void N_nivelOrden();
};

#include "NodoGeneral.hxx"