#pragma once 

#include <iostream>
#include <list>
#include <queue>
using namespace std;


template <typename T>
struct NodoGeneral
{
    //datos
    T dato;
    list<NodoGeneral<T>*> p_hijos;

    //constructor ??
    NodoGeneral();
    
    //destructor ??
    ~NodoGeneral();
    
    //operaciones
    T& obtenerDato(); //que significa devolver una referencia?
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