#pragma once 

#include <list>
using namespace std;


template <typename T>
struct Nodo
{
    private:
    //datos
        T dato;
        list<Nodo<T>*> p_hijos; //Nodo<T>* sig seria como lo haciamos en la lista, un apuntador a un dato;
    //de tipo nodo aqui es un conjunto de apuntadores a datos de tipo nodo y por eso se hace así
    
    //operaciones

    /*
    //constructor ?????????????????????? (VER HOJITA PARA PREGUNTAR)
    Nodo(){
        p_hijos.clear();
    }
    */
    Nodo(T dato){
        this->dato = dato; //equivalente a Nodo* p = this; p->dato = dato;
    }
    /*
    //destructor ?????????????????????????????'
    ~Nodo(){
        for(auto it = p_hijos.begin(); it!= p_hijos.end(); it++)
            delete *it; //estamos borrando los apuntadores a los p_hijos del nodo
        p_hijos.clear();
    }
    */

    //operaciones
    T& obtenerDato(); //?????? T&?? que significa devolver una referencia? que extraño...
    void cambiarDato(T& nuevoDato);
    void limpiarLista();
    void agregarHijo(T& Dato); 
    bool eliminarHijo(T& Dato); 
};

#include "Nodo.hxx"