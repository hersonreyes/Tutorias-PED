//Ejercicio: Ingresar n elementos REALES en una lista y calcular el mayor, el menor y el promedio .

#include <iostream>
using namespace std;

struct Nodo
{
    float dato;
    Nodo *sig;
};
Nodo *Lista;

void insertaAlFinal(float n)
{
   Nodo *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->sig = NULL;
    
    if (Lista == NULL) {
        Lista = nuevo;
    } else {
        Nodo *p = Lista;
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
    Nodo *s = Lista;

    while (s != NULL) {
        cout<< s->dato<<endl;
        s = s->sig;
    } 
}

float mayor()
{
    Nodo *p = Lista;
    float may;
    may = p->dato;
    while (p != NULL)
    {
        if (p->dato > may)
            may = p->dato;
        p = p->sig;
    }
    return may;
}

float menor()
{
    Nodo *p = Lista;
    float men;
    men = p->dato;
    while (p != NULL)
    {
        if (p->dato < men)
            men = p->dato;
        p = p->sig;
    }
    return men;
}

float promedio()
{
    Nodo *p = Lista;
    float s = 0;
    int c = 0;
    Nodo *p;
    while (p != NULL)
    {
        s = s + p->dato;
        c++;
        p = p->sig;
    }
    return s / c;
}

void sumaPares()
{
    Nodo *l = Lista;
    float s = 0;
    int c = 0;
    int suma = 0;
    int num=0;
    cout<<"Los numeros pares encontrados en la lista son: ";
    while (l != NULL)
    {
     num=l->dato;   
        if(num%2==0){
             cout<<num<<endl;
            suma+=num; 
        }
        l=l->sig;
    }
  cout<<"La suma de los pares es:"<<suma<<endl;
}

void sumaImpares()
{
    Nodo *l = Lista;
    float s = 0;
    int c = 0;
    int suma = 0;
    int num=0;
    cout<<"Los numeros impares encontrados en la lista son: "<<endl;
    while (l != NULL)
    {
     num=l->dato;   
        if(num%2!=0){
             cout<<num<<endl;
            suma+=num; 
        }
        l=l->sig;
    }
  cout<<"La suma de los impares es:"<<suma<<endl;
}

void eliminar(){
    float num = 0;
    cout << "Numero a eliminar: ";
    cin >> num;

    Nodo *p = Lista, *q = NULL;

    while(p != NULL && p->dato != num){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Numero no existe" << endl;
        return;
    }
    if(q == NULL)
        Lista = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Numero borrado!" << endl;
}

float sumarLista(){
    Nodo *l = Lista;
    float suma=0;
    while(l!=NULL){
        suma+=l->dato;
        l=l->sig;
    }
    return suma;
}


void menu(){
    cout<<"Ingresa una opcion"<<endl;
    cout<<"1) Ingresar datos"<<endl;
    cout<<"2) mostrar datos"<<endl;
    cout<<"3) Ver el mayor dato"<<endl;
    cout<<"4) Ver el dato promedio"<<endl;
    cout<<"5) Suma de numeros impares"<<endl;
    cout<<"6) Suma de numeros pares"<<endl;
    cout<<"7) Eliminar Nodo"<<endl;
    cout<<"8) Sumar Lista"<<endl;
    cout<<"9 para salir..."<<endl;
}

int main(int argc, char *argv[])
{
    Nodo *lista = NULL;
    int opc;

    do{
        float n;
        menu();
        cin>>opc;
        cout<<"La opcion elegida es "<< opc<<endl;
        switch (opc)
        {
        case 1:
            cout<<"Ingrese el numero"<<endl;
            cin>>n;
            insertaAlFinal(n);
            break;  
        case 2:
            mostrarLista();
            break;      
        case 3:
            cout << "El mayor es : " << mayor() << endl;
            break;
        case 4: 
            cout << "El prmedio es : " << promedio() << endl;
            break;
        case 5:
          sumaPares();
          break;
         case 6:
         sumaImpares();
         break;
         case 7:
         eliminar();
         break;
         case 8:
         cout<<"La suma de toda la lista es: "<<sumarLista()<<endl;
         break;
        default:
            break;
        }

    }while(opc!=9);

    return 0;
}