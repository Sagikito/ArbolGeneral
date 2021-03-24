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


//indica si un nodo es hoja
template <typename T>
bool NodoGeneral<T>::esHoja()
{
    return p_hijos == 0;
}


//calculo de la altura del subarbol con raiz en nodo (esta es mi propuesta)
template <typename T>
int NodoGeneral<T>::N_altura()
{
    if(esHoja())
        return 0;
    else
    {
        int max = 0;
        for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->N_altura() > max)
                max = (*it)->N_altura();
        return 1 + max;
    }
}

//esta es mi implementacion de tamano 
//calcula el numero de nodos en el subarbol con el nodo actual como raiz
template <typename T>
unsigned int NodoGeneral<T>::N_tamano()
{
    if(esHoja())
        return 1;
    else
    {
        int numNodos = 0;
        list<NodoGeneral<T>*>::iterator it;
        for(it = p_hijos.begin(); it != p_hijos.end(); it++)
            numNodos += (*it)->N_tamano();
        return numNodos + 1;
    }
}



//crea un NodoGeneral con cierto dato y un apuntador a si mismo y luego lo conecta a la lista de apuntadores a hijos que ya tenemos
template <typename T>
void NodoGeneral<T>::agregarHijo(T& Dato) 
{
    NodoGeneral<T>* nuevo = new NodoGeneral<T>;
    nuevo->fijarDato(Dato);
    p_hijos.push_back(nuevo);
}


//si es nodo hoja el iterador it donde queda?
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


//inserta un nuevo dato dado, en algun dato padre.
template <typename T>
bool NodoGeneral<T>::N_insertarNodo(T datoPadre, T nuevoDato)
{
    //agregamos el nuevo dato si el nodo en el que estamos es el padre que deseamos
    if(dato == datoPadre)
    {
        agregarHijo(nuevoDato);
        return true;
    }
    //revisamos a ver si en los hijos esta el padre que buscamos
    else
    {
        list<NodoGeneral<T>*>::iterator it;

        //si en algun momento se puede insertar, lo insertamos
        for(it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->N_insertarNodo(datoPadre,nuevoDato))
                return true;
        
        return false;
    }
}


//eliminamos el nodo haciendo la busqueda desde los hijos del nodo actual
template <typename T>
bool NodoGeneral<T>::N_eliminarNodo(T datox)
{
    if(eliminarHijo(datox))
        return true;
    else
    {
        list<NodoGeneral<T>*>::iterator it;

        for(it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->eliminarHijo(datox))
                return true;

        return false;
    }
}

//al parecer buscar solo me dice si si esta o no en este subarbol
//como podria obtener ademas de el bool de si esta o no
//una referencia al dato encontrado?

template <typename T>
bool NodoGeneral<T>::N_buscarNodo(T datob)
{
    if(dato == datob)
        return true;
    else
    {
        list<NodoGeneral<T>*>::iterator it;

        for(it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->N_buscarNodo(datox))
                return true;
    
        return false;
    }
}


//antes tenia las anteriores tres funciones de esta forma:
/*

template <typename T>
bool NodoGeneral<T>::N_buscarNodo(T datob)
{
    if(dato == datob)
        return true;
    else
    {
        list<NodoGeneral<T>*>::iterator it;
        for(it = p_hijos.begin(); it != p_hijos.end(); it++)
        {
            if(!((*it)->N_buscarNodo(datox)))
                continue;
        }
        return false;
    }

}
*/


//---------------------------------------------------------------------------------------------------------------
//nota: las siguientes funciones podrian  ser mejor de tipo list<NodoGeneral<T>> almacenando los datos en preorden

//impresion del preorden del subarbol cuya raiz es el nodo actual
template <typename T>
void NodoGeneral<T>::N_preOrden()
{
    cout<<obtenerDato()<<" ";
    for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
        (*it)->N_preOrden();
}

//impresion en posorden del subarbol cuya raiz es el nodo actual
template <typename T>
void NodoGeneral<T>::N_posOrden()
{
    for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
        (*it)->N_posOrden();
    cout<<obtenerDato()<<" ";
}

//impresion por niveles del subarbol cuya raiz es el nodo actual
template<typename T>
void NodoGeneral<T>::N_nivelOrden()
{
    //creamos una queue con apuntadores a nodos
    queue<NodoGeneral<T>*> fila;

    //metemos el apuntador al nodo actual
    fila.push(this);
    
    //el ciclo termina cuando ya no haya nadie en la fila
    while(!fila.empty())
    {
        NodoGeneral<T>* actual = fila.front();
        //imprimimos el dato del nodo actual
        cout<<actual->obtenerDato();
        
        //agregamos los hijos del nodo actual a la fila (como apuntadores)
        list<NodoGeneral<T>*>::iterator it;
        for(it = actual->(p_hijos.begin()); it != actual->(p_hijos.end()); it++)
            fila.push(*it);
        fila.pop();
        //eliminamos el nodo (como apuntador) con el que estabamos trabajando
    }
}