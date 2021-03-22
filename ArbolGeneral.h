#pragma once
#include "NodoGeneral.h"

template <typename T>
struct ArbolGeneral
{
    protected:
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

    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);

    //esta la cambie...
    unsigned int altura();

    unsigned int tamano();

    void preOrden();
    void posOrden();
    void nivelOrden();
};

//deja el apuntador raiz en nulo
template <typename T>
ArbolGeneral<T>::ArbolGeneral()
{
    raiz = NULL; //recordar #define NULL 0
}

//crea un arbol con solo su raiz
template <typename T>
ArbolGeneral<T>::ArbolGeneral(T& dato)
{
    NodoGeneral<T>* nuevo = new NodoGeneral<T>;
    nuevo -> fijarDato(dato);
    raiz = nuevo;
}

//destruccion del arbol
template <typename T>
ArbolGeneral<T>::~ArbolGeneral()
{
    delete raiz; //?????????? aca tampoco entiendo T_T o sea borra recursivamente o que esta haciendo?
    raiz = NULL;
}

//retorna si el arbol es vacio o no
template <typename T>
bool ArbolGeneral<T>::esVacio()
{
    return raiz == NULL;
}

//devuelve el apuntador raiz
template <typename T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz()
{
    return raiz;
}

//cambia la raiz del arbol
template <typename T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz)
{
    raiz = nraiz;
}


/*  FALTAN ESTAS OPERACIONES
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);
*/

//esta es mi propuesta de altura sobre un arbol
template <typename T>
unsigned int ArbolGeneral<T>::altura()
{
    if(esVacio())
        return -1;
    else
        return raiz->altura();
}