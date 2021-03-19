#pragma once 

#include <list>
using namespace std;


template <typename T>
struct Nodo
{
    //datos
    T dato;
    list<Nodo<T>*> hijos; //Nodo<T>* sig seria como lo haciamos en la lista, un apuntador a un dato;
    //de tipo nodo aqui es un conjunto de apuntadores a datos de tipo nodo y por eso se hace así
    //operaciones
};