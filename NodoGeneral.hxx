#include "NodoGeneral.h"

//constructor
template <typename T>
NodoGeneral<T>::NodoGeneral()
{
    p_hijos.clear();
}

//destructor
template<typename T>
NodoGeneral<T>::~NodoGeneral()
{
    for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
        delete *it;
    p_hijos.clear();
}

//obtiene el dato del nodo actual
template <typename T>
T NodoGeneral<T>::obtenerDato()
{
    //T& ref = dato;
    //return ref;
    return dato;
}


//cambia el dato de un NodoGeneral
template <typename T>
void NodoGeneral<T>::fijarDato(T& NuevoDato)
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
    return p_hijos.size() == 0;
}

//calculo de la altura del subarbol con raiz en nodo en nodo actual
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

//calcula el numero de nodos en el subarbol con el nodo actual como raiz
template <typename T>
unsigned int NodoGeneral<T>::N_tamano()
{
    if(esHoja())
        return 1;
    else
    {
        int numNodos = 0;
        for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
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


/*
    si es nodo hoja el iterador it donde queda?
*/

//elimina un hijo (si lo encuentra)
template <typename T>
bool NodoGeneral<T>::eliminarHijo(T& Dato)
{
    
    //buscar si existe un nodo con el Dato dado
    NodoGeneral<T>* aux;
	auto it = p_hijos.begin();
    for(it = p_hijos.begin(); it != p_hijos.end(); it++)
    {
        aux = *it; //el contenido de it es un apuntador!
        if(aux->obtenerDato() == Dato)
            break;
    }

    //si lo encontramos, eliminarlo
    if(it != p_hijos.end())
    {
        delete *it; //?????la profe dice que el destructor se encarga de todo pero aun no entiendo bien eso...
        p_hijos.erase(it);
        return true;
    }
    return false;
}

//inserta un nuevo dato dado, en algun dato padre (si lo encuentra)
template <typename T>
bool NodoGeneral<T>::N_insertarNodo(T datoPadre, T nuevoDato)
{
    //agregamos el nuevo dato si el nodo en el que estamos es el padre que deseamos
    bool res = false;
    if(this->dato == datoPadre)
    {
        agregarHijo(nuevoDato);
        res = true;
    }
    //revisamos a ver si en los hijos esta el padre que buscamos
    else
    {
        //si en algun momento se puede insertar, lo insertamos
        
        for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->N_insertarNodo(datoPadre,nuevoDato))
                res = true;
    }
    return res;
}


//eliminamos el nodo haciendo la busqueda desde los hijos del nodo actual
template <typename T>
bool NodoGeneral<T>::N_eliminarNodo(T datox)
{
    if(eliminarHijo(datox))
        return true;
    else
    {
        for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->eliminarHijo(datox))
                return true;

        return false;
    }
}

/*
al parecer buscar solo me dice si si esta o no en este subarbol
como podria obtener ademas de el bool de si esta o no
una referencia al dato encontrado?
*/

//busca un nodo a partir del subarbol con raiz nodo actual
template <typename T>
bool NodoGeneral<T>::N_buscarNodo(T datob)
{
    if(dato == datob)
        return true;
    else
    {
        for(auto it = p_hijos.begin(); it != p_hijos.end(); it++)
            if((*it)->N_buscarNodo(datob))
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
//nota: las siguientes funciones podrian  ser mejor de tipo 
//list<NodoGeneral<T>> almacenando los datos en preorden

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
        
        //agregamos los hijos del nodo actual a la fila (como apuntadores);
        for(auto it = actual->p_hijos.begin(); it != actual->p_hijos.end(); it++)
            fila.push(*it);
        fila.pop();
        //eliminamos el nodo (como apuntador) con el que estabamos trabajando
    }
}