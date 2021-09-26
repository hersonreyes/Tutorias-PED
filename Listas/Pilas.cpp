#include <iostream>
using namespace std;

class Pila {
    private:
    struct Nodo{
        int info;
        Nodo *sig;
    };
    Nodo *raiz;
    int numero=10;
    
    public:
    Pila();
    void push(int x);
    void push(int x,int y);
    int getNumber();
    void print();
    int top();
    int pop();
    void setNumber(int x);
    void push();
};

Pila::Pila(){
    raiz=NULL;
}

int Pila::getNumber(){
    return numero;
}

void Pila::setNumber(int x){
    numero=x;
}

int Pila::pop(){
     if(raiz!=NULL){
        int informacion = raiz->info;
        Nodo *bor = raiz;
        raiz=raiz->sig;
        delete bor;
        return informacion;
    }
    
    else {
        return -1;
    }
}

int Pila::top(){
    if(raiz!=NULL){
        int informacion = raiz->info;
        return informacion;
    }
    
    else {
        return -1;
    }
}

void Pila::push(int x){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    }
    else {
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}

void Pila::push(int x, int y){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info=x+y;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    }
    else {
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}

void Pila::push(){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info=80;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    }
    else {
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}
    
void Pila::print(){
    Nodo *reco=raiz;
    while(reco!=NULL){
        cout<<reco->info<<endl;
        reco=reco->sig;
    }
}
    


int main(){
    Pila *pila1;
    pila1 = new Pila();
    pila1->push(50);
    pila1->push(40);
    pila1->print();
    cout<<"El tope de la pila es "<<pila1->top()<<endl;
    pila1->push(55);
    pila1->push(70);
     cout<<"El tope de la pila es "<<pila1->top()<<endl;
     cout<<"Elemento extraido de la pila "<<pila1->pop()<<endl;
     cout<<"El tope de la pila es "<<pila1->top()<<endl;
     pila1->push();
     cout<<"El tope de la pila es "<<pila1->top()<<endl;
     pila1->push(20,20);
       cout<<"El tope de la pila es "<<pila1->top()<<endl;
       cout<<pila1->getNumber()<<endl;
       pila1->setNumber(77);
            cout<<pila1->getNumber();
       
     
     
     
    
    return 0;
}
