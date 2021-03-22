#pragma once 

#include <list>
using namespace std;


template <typename T>
struct NodoGeneral
{
    private:
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

    unsigned int altura();
    void agregarHijo(T& Dato); 
    bool eliminarHijo(T& Dato); 
};

#include "NodoGeneral.hxx"