#include "Nodo.h"

/*????????????????'
Asi es como yo la haria, devolver el dato directamente, no entiendo muy bien porque la profe lo hace como referencia..
template <typename T>
T Nodo<T>::obtenerDato()
{
    return dato;
}
*/

//funcion que retorna una referencia (alias) al dato que tenemos en Nodo T& ref = dato 
template <typename T>
T& Nodo<T>::obtenerDato()
{
    //T& ref = dato;
    //return ref;
    return dato;
}


/*
???????????
otra opcion seria retornar un apuntador al dato del Nodo
template <typename T>
T* Nodo<T>::obtenerDato()
{
    T* p= &dato;
    return p;
    return &dato;
}
*/

//cambia el dato de un nodo
template <typename T>
void Nodo<T>::cambiarDato(T& NuevoDato) //??????supongo que la referencia se hace para no copiar y pegar el nuevodato que se está enviando
{
    dato = NuevoDato;
}


//elimina los hijos de un nodo
template <typename T>
void Nodo<T>::limpiarLista()
{
    p_hijos.clear();
}

//crea un nodo con cierto dato y un apuntador a si mismo y luego lo conecta a la lista de apuntadores a hijos que ya tenemos
template <typename T>
void Nodo<T>::agregarHijo(T& Dato) 
{
    Nodo<T>* nuevo = new Nodo<T>;
    nuevo->cambiarDato(Dato);
    p_hijos.push_back(nuevo);
}

template <typename T>
bool Nodo<T>::eliminarHijo(T& Dato)
{
    list<Nodo<T>*>::iterator it; //auto it menos fastidioso
    Nodo<T>* aux;

    for(it = p_hijos.begin(); it != p_hijos.end(); it++)
    {
        aux = *it; //el contenido de it es un apuntador!
        if(*it->obtenerDato() == Dato)
            break;
    }

    if(it != p_hijos.end())
    {
        delete aux; //??????????????ella dice que aqui el destructor se encarga de todo pero aun no entiendo bien este delete...
        p_hijos.erase(it);
        return true;
    }
    return false;
}