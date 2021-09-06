#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

Nodo *pInicio;

void insertarAlPrincipio(int);
void insertarAlFinal(int);
void mostrarLista();

int main()
{
    int x;
    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar al Principio\n\t2) Agregar al Final"
             << "\n\t3) Mostrar Numeros"
             << "\n\t4) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Que numero desea agregar" << endl;
            cin >> x;
            insertarAlPrincipio(x);
            break;
        case 2:
            cout << "Que numero desea agregar" << endl;
            cin >> x;
            insertarAlFinal(x);
            break;
        case 3:
            cout << "Mostrando Lista..." << endl;
            mostrarLista();
            break;
        case 4:
            continuar = false;
            break;
        default:
            cout << "Opcion erronea!" << endl;
            break;
        }
    } while (continuar);
    return 0;
}

void insertarAlPrincipio(int n)
{
  Nodo *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void insertarAlFinal(int n)
{
   Nodo *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void mostrarLista()
{
    Nodo *s = pInicio;

    while (s != NULL) {
        cout<< s->dato<<endl;
        s = s->sig;
    } 
}