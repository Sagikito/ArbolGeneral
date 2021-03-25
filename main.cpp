#include "ArbolGeneral.h"

int main()
{
    ArbolGeneral<int> arbol;
    short opcion; cin>>opcion;

    do
    {
        cout<<"Escoja la opcion que desee"<<endl;
        
        //cout<<"1. Crear arbol vacio"<<endl;
        //cout<<"2. Crear arbol con un dato"<<endl;
        cout<<"3. Destruir el Arbol"<<endl;
        cout<<"4. Verificar si el Arbol esta vacio"<<endl;
        cout<<"5. Insertar un nuevo dato"<<endl;
        cout<<"6. Eliminar un dato"<<endl;
        cout<<"7. Buscar un dato"<<endl;
        cout<<"8. Calcular la altura del arbol"<<endl;
        cout<<"9. Calcular tamano del arbol"<<endl;
        cout<<"10. Imprimir arbol en preOrden"<<endl;
        cout<<"11. Imprimir arbol en posOrden"<<endl;
        cout<<"12. Imprimir arbol por niveles"<<endl;
        cout<<"13. Salir"<<endl;

        switch (opcion)
        {
        //crear Arbol Vacio
        /*case 1:
        {
            cout<<"Arbol Creado!"<<endl;
            break;
        }
        
        //crear arbol con un dato
        case 2:
        {
            int dato;
            cout<<"Ingrese el dato: "<<endl;
            cin>>dato;
            arbol = arbol(dato<<endl;
            cout<<"Arbol Creado con el dato!"<<endl;
            break;
        }
        */

        //destruccion del arbol
        case 3:
        {
            arbol.~ArbolGeneral();
            cout<<"arbol eliminado!"<<endl;
            break;
        }
        
        //verificar si es Vacio
        case 4:
        {
            if(arbol.esVacio())
                cout<<"El arbol esta vacio!"<<endl;
            else
                cout<<"El arbol tiene datos!"<<endl;
            break;
        }


        //insertar un dato
        case 5:
        {
            int padre, nuevo;
            cout<<"Ingrese el dato padre: "<<endl;
            cin>>padre;
            cout<<"Ingrese el nuevo dato: "<<endl;
            cin>>nuevo;
            if(arbol.A_insertarNodo(padre, nuevo))
                cout<<"Dato insertado!"<<endl;
            else
                cout<<"El dato no fue insertado"<<endl;
            break;
        }

        //eliminar un dato
        case 6:
        {
            int datox;
            cout<<"Ingrese el dato a eliminar"<<endl;
            cin>>datox;
            if(arbol.A_eliminarNodo(datox))
                cout<<"Dato eliminado!"<<endl;
            else
                cout<<"El dato no ha sido eliminado"<<endl;
            break;
        }

        //Buscar un dato
        case 7:
        {
            int dato_b;
            cout<<"Ingrese el dato a buscar: "<<endl;
            cin>>dato_b;
            if(arbol.A_buscarNodo(dato_b))
                cout<<"El dato esta en el arbol";
            else
                cout<<"El dato no esta en el arbol";
            break;
        }

        //Altura del arbol
        case 8:
        {
            cout<<"La altura del arbol es: ";
            cout<<arbol.A_altura()<<endl;
            break;
        }

        //Tamano del arbol
        case 9:
        {
            cout<<"El tamano del arbol es: ";
            cout<<arbol.A_tamano()<<endl;
            break;
        }

        //preOrden
        case 10:
        {
            arbol.A_preOrden();
            break;
        }

        //posOrden
        case 11:
        {
            arbol.A_posOrden();
            break;
        }

        //niveles
        case 12:
        {
            arbol.A_nivelOrden();
            break;
        }

        default:
        {
            cout<<"Saliendo del programa..."<<endl;
            break;
        }
        }

    }while(opcion > -1 && opcion < 13);
}