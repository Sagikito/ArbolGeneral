#pragma once
#include "NodoGeneral.h"

template <typename T>
struct ArbolGeneral
{
    //nodo raiz
    NodoGeneral<T>* raiz;

    //Constructores
    ArbolGeneral();
    ArbolGeneral(T dato);

    //Destructor
    ~ArbolGeneral();

    //Metodos
    bool esVacio();

    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);

    bool A_insertarNodo(T datoPadre, T datoNuevo);
    bool A_eliminarNodo(T datox);
    bool A_buscarNodo(T datob);

    int A_altura(); //inicialmente estaba como unsigned pero si era -1 paila
    unsigned int A_tamano();

    void A_preOrden();
    void A_posOrden();
    void A_nivelOrden();
};

#include "ArbolGeneral.hxx"