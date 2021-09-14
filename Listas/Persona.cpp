#include <iostream>
#include <string>
using namespace std;

struct Estudiante{
    int carnet;
    string nombre;
    string apellido;
    int telefono;
    string correo;
};
typedef struct Estudiante Es;

Es solicitarpersona(){
    Es p;
    

    cout << "Carnet: "; cin >> p.carnet;
    cin.ignore();
    cout << "Nombres: "; getline(cin, p.nombre);
    cout << "Apellidos: "; getline(cin, p.apellido);
    cout<<"Telefono   "; cin>>p.telefono;
    cin.ignore();
    cout<< "Correo: "; getline(cin, p.correo);
    return p;
}

void mostrarpersona(Es p){
    cout << "Carnet: " << p.carnet << endl;
    cout << "Nombres: " << p.nombre << endl;
    cout << "Apellidos: " << p.apellido << endl;
    cout << "Telefono "<<p.telefono<<endl;
    cout << "Correo "<<p.correo<<endl;
    cout<<" "<<endl;
  
}

struct TNodo{
    Es dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Es p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Es p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
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

void insertarDespuesDe(Es p) {
    int Carnet = 0;
    cout << "Inserte un Carnet: ";
    cin >> Carnet;
    
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).carnet != Carnet)
        s = s->sig;
    if(s == NULL){
        cout << "Persona NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;
    
    s->sig = nuevo;
    cout << "Persona Registrada con exito" << endl;
}

void insertarAntesDe(Es p) {
    int Carnet = 0;
    cout << "Inserte un carnet de referencia: ";
    cin >> Carnet;
    
    Nodo *s = pInicio, *q = NULL;
    
    while(s != NULL && (s->dato).carnet != Carnet){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "Libro de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s;
    
    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Persona registrada con exito" << endl;
}

void agregarpersona(){
    Es p = solicitarpersona();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\t3) Despues de\n\t4) Antes de"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
            case 3: insertarDespuesDe(p);   continuar = false;
            break;
            case 4: insertarAntesDe(p);   continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarpersona(s->dato);
        s = s->sig;
    } 
}

void eliminarpersona(){
    int Carnet = 0;
    cout << "Carnet de persona a eliminar: ";
    cin >> Carnet;
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && (p->dato).carnet != Carnet){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Persona NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Persona borrada!" << endl;
}

void buscarpersona() {
    int Carnet = 0;
    cout << "Carnet de persona a buscar: ";
    cin >> Carnet;
    
    Nodo *s = pInicio;

    while(s != NULL && (s->dato).carnet != Carnet)
        s = s->sig;
        
        
  if(s!=NULL){
       cout << "Carnet: " <<endl;cin>> (s->dato).carnet ;
    cout << "Nombres: " << endl;cin>>(s->dato).nombre;
    cout << "Apellidos: " << endl;cin>>(s->dato).apellido;
    cout << "Telefono "<< endl; cin>>(s->dato).telefono;
    cout << "Correo "<<endl; cin>>(s->dato).correo;
 
  }
  
  else cout<<"Persona no encontrada"<<endl;
    
    
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Persona\n\t2) Ver Personas"
            << "\n\t3) Eliminar Personas\n\t4) Actualizar Persona"
            << "\n\t5) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarpersona();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: cout << "Eliminando..." << endl;
                eliminarpersona();
            break;
            case 4: cout << "Buscando..." << endl;
                buscarpersona();
                  
            break;
            case 5: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}