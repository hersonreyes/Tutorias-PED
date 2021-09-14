#include <iostream>
#include <time.h>
using namespace std;

struct TNodo{
    int dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(int num) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = num;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void agregarNumero(){
    int num = 0,c,i;
    cout<<"Digite la cantidad de numeros aleatorios que desea ingresar"<<endl;
    cin>>c;
    srand(time(NULL));

    for(i = 1; i <= c; i++)
    {
        num = 1 + rand() % (101 - 1);
       insertarInicio(num);
    }
    
    
}
 
void mostrarinvert(){
    Nodo *s=pInicio;
    int i=0,arr[100],j;
    
    while(s!=NULL){
      arr[i]=(s->dato);
      s=s->sig;
      i++;
    }
    
 for(j=(i-1);j>=0;j--)  
 {
     cout<<arr[j]<<endl;;
 } 
     
    

}

   
void mostrar() {
    Nodo *s = pInicio;

    while (s != NULL) {
        cout << (s->dato) << endl;
        s = s->sig;
}
}

void mostrarpares() {
    Nodo *s = pInicio;

    while (s != NULL) {
        if (((s->dato)%2)==0){
        cout << (s->dato) << endl;
        s = s->sig;
        }
    else s=s->sig;
    }
}
void mostrarimpares() {
    Nodo *s = pInicio;

    while (s != NULL) {
        if (((s->dato)%2)!=0){
        cout << (s->dato) << endl;
        s = s->sig;
        }
    else s=s->sig;
    }
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Numero\n\t2) Ver todos los numeros"
            << "\n\t3) Ver Pares\n\t4) Ver impares\n\t5) Ver Invertido\n\t6) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarNumero();
            break;
            case 2: cout << "Listando..." << endl;
                mostrar();
            break;
             case 3: cout << "Listando..." << endl;
                mostrarpares();
                break;
             case 4: cout << "Listando..." << endl;
             mostrarimpares();
             break;
              case 5: cout << "Listando..." << endl;
             mostrarinvert();
            break;
            case 6: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}