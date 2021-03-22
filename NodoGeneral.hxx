#include "NodoGeneral.h"


//no lo entiendo (para que hacemos eso en el constructor? no es equivalente dejarlo vacio y ya?)
template <typename T>
NodoGeneral<T>::NodoGeneral()
{
    p_hijos.clear();
}

//no entiendo tampoco bien el destructor... que significa bien ese delete (aca si me parece que tiene sentido el clear de la lista)
//sin embargo por que entonces el constructor tambien tiene ese p_hijos.clear()?)
template<typename T>
NodoGeneral<T>::~NodoGeneral()
{
    for(auto it = p_hijos.begin(), it != p_hijos.end(); it++)
        delete *it
    p_hijos.clear();
}

//????????????????????????
//funcion que retorna una referencia (alias) al dato que tenemos en NodoGeneral T& ref = dato ?
template <typename T>
T& NodoGeneral<T>::obtenerDato()
{
    //T& ref = dato;
    //return ref;
    return dato;
}

/*????????????????'
Asi es como yo la haria, devolver el dato directamente, no entiendo muy bien porque la profe lo hace como referencia..
template <typename T>
T NodoGeneral<T>::obtenerDato()
{
    return dato;
}
*/

/*
???????????
otra opcion seria retornar un apuntador al dato del NodoGeneral
template <typename T>
T* NodoGeneral<T>::obtenerDato()
{
    T* p= &dato;
    return p;
    return &dato;
}
*/

//cambia el dato de un NodoGeneral
template <typename T>
void NodoGeneral<T>::fijarDato(T& NuevoDato) //??????supongo que la referencia se hace para no copiar y pegar el nuevodato que se está enviando
{
    dato = NuevoDato;
}


//elimina los hijos de un NodoGeneral
template <typename T>
void NodoGeneral<T>::limpiarLista()
{
    p_hijos.clear();
}


//calculo de la altura del subarbol con raiz en nodo (esta es mi propuesta)
template <typename T>
unsigned int NodoGeneral<T>::altura()
{
    if(p_hijos.size() == 0)
        return 0;
    else
    {
        max = 0;
        for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->altura() > max)
                max = (*it)->altura();
        return 1 + max;
    }
}



//crea un NodoGeneral con cierto dato y un apuntador a si mismo y luego lo conecta a la lista de apuntadores a hijos que ya tenemos
template <typename T>
void NodoGeneral<T>::agregarHijo(T& Dato) 
{
    NodoGeneral<T>* nuevo = new NodoGeneral<T>;
    nuevo->FijarDato(Dato);
    p_hijos.push_back(nuevo);
}

//elimina un hijo (si lo encuentra)
template <typename T>
bool NodoGeneral<T>::eliminarHijo(T& Dato)
{
    
    //buscar si existe un nodo con el Dato dado
    list<NodoGeneral<T>*>::iterator it;
    NodoGeneral<T>* aux;

    for(it = p_hijos.begin(); it != p_hijos.end(); it++)
    {
        aux = *it; //el contenido de it es un apuntador!
        if(aux->obtenerDato() == Dato)
            break;
    }

    //si lo encontramos, eliminarlo
    if(it != p_hijos.end())
    {
        delete *it; //??????????????ella dice que aqui el destructor se encarga de todo pero aun no entiendo bien eso...
        p_hijos.erase(it);
        return true;
    }
    return false;
}