
#include <iostream>

using namespace std;

struct Nodo{
  int dato;
  Nodo* sig;
  Nodo* ant;
};

Nodo* cab;

void insertar(int d){
    Nodo *nuevo = new Nodo;
    nuevo->dato= d;
    nuevo->ant=NULL;
    if(cab==NULL){
        nuevo->sig=NULL;
        cab=nuevo;
    }
    
    else {
        nuevo->sig =cab;
        cab->ant=nuevo;
        cab=nuevo;
    }
}


void insertarFinal(int d){
    Nodo* nuevo = new Nodo;
    nuevo->dato= d;
    nuevo->sig=NULL;
    if(cab==NULL){
        nuevo->ant=NULL;
        cab=nuevo;
    }
    else {
        Nodo *aux=cab;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig = nuevo;
        nuevo->ant=aux;
    }
}

void mostrar(){
    Nodo* aux= cab;
    while(aux!=NULL){
        cout<<aux->dato<<endl;
        aux=aux->sig;
    }
}

void mostrarInvertido(){
    Nodo* aux =cab;
    while(aux->sig!=NULL){
        aux=aux->sig;
    }
    
    while(aux!=NULL){
        cout<<aux->dato<<endl;
        aux=aux->ant;
    }
}

void eliminar(){
    int num=0;
    cout<<"Ingrese el numero a eliminar"<<endl;
    cin>>num;
    
    Nodo *p=cab, *q=NULL;
    
    while(p!=NULL and p->dato != num){
        q=p;
        p=p->sig;
    }
    
    if(p==NULL){
        cout<<"Numero no existe"<<endl;
        return;
    }
    
    if(q==NULL){
        cab=p->sig;
    }
    
    else{
        q->sig= p->sig;
        if(p->sig!=NULL) (q->sig)->ant = q;
    }
    
    delete(p);
    cout<<"Numero borrado"<<endl;
}




int main()
{
 
 int opc;

    do{
        int n;
        cout<<"1- agregar al principio"<<endl;
        cout<<"2- agregar al final"<<endl;
        cout<<"3- mostrar"<<endl;
        cout<<"4- mostrarInvertido"<<endl;
        cout<<"5- Eliminar"<<endl;
        cin>>opc;
        cout<<"La opcion elegida es "<< opc<<endl;
        switch (opc)
        {
        case 1:
            cout<<"Ingrese el numero"<<endl;
            cin>>n;
            insertar(n);
            break;  
        case 2:
            cout<<"Ingrese el numero"<<endl;
            cin>>n;
            insertarFinal(n);
            break;      
        case 3:
            mostrar();
            break;
        case 4: 
          mostrarInvertido();
            break;
         case 5:
         eliminar();
         break;
        default:
            break;
        }

    }while(opc!=6);
    return 0;

    return 0;
}
