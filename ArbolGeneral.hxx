#include "ArbolGeneral.h"

//deja el apuntador raiz en nulo
template <typename T>
ArbolGeneral<T>::ArbolGeneral()
{
    raiz = NULL; //recordar #define NULL 0
}

//crea un arbol con solo su raiz
template <typename T>
ArbolGeneral<T>::ArbolGeneral(T dato)
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

//inserta un nuevo dato en el arbol
template <typename T>
bool ArbolGeneral<T>::A_insertarNodo(T datoPadre, T nuevoDato)
{
    //si el arbol es vacio llamo al constructor????????
    if(esVacio())
    {
        ArbolGeneral(nuevoDato);
        return true;
    }
    //si no es vacio, llamamos a la funcion N_insertarNodo sobre la raiz
    else
        return raiz->N_insertarNodo(datoPadre, nuevoDato);
}

//elimina un datox del Arbol
template <typename T>
bool ArbolGeneral<T>::A_eliminarNodo(T datox)
{
    if(esVacio())
        return false;
    else if(raiz->dato == datox)
    {
       //aca se llama al destructor??????
       this->~ArbolGeneral();
       return true;
    }
    else
        return raiz->N_eliminarNodo(datox);
}

//busca un datob dentro del arbol
template <typename T>
bool ArbolGeneral<T>::A_buscarNodo(T dato_b)
{
    if(esVacio())
        return false;
    else
        return raiz->N_buscarNodo(dato_b);
}


//esta es mi propuesta de altura sobre un arbol
template <typename T>
int ArbolGeneral<T>::A_altura()
{
    if(esVacio())
        return -1;
    else
        return raiz->N_altura();
}

template <typename T>
unsigned int ArbolGeneral<T>::A_tamano()
{
    if(esVacio())
        return 0;
    else 
        return raiz->N_tamano();
}


//imprime en preorden los nodos del arbol
template <typename T>
void ArbolGeneral<T>::A_preOrden()
{
    if(esVacio())
        cout<<"El arbol esta vacio!"<<endl;
    else
        raiz->N_preOrden();
}

//imprime en posorden los nodos del arbol
template <typename T>
void ArbolGeneral<T>::A_posOrden()
{
    if(esVacio())
        cout<<"El arbol esta vacio!"<<endl;
    else
        raiz->N_posOrden();
}

//imprime por niveles los nodos del arbol
template <typename T>
void ArbolGeneral<T>::A_nivelOrden()
{
    raiz->N_nivelOrden();
}