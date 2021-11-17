#include "Grafo.h"

Grafo::Grafo(){
    cout << "Constructor Grafo" <<endl;
    // TODO: Crear constructor
    // TODO: Inicializar el resto de estructuras
    for(int i=0; i < sizeof(Grafo::Cjtovertices)/sizeof(string); i++){
        Grafo::Cjtovertices[i] = "";
    }


}

void Grafo::insertNodo(string n){
    bool insert = false;
    int i = 0;
    while(!insert && i<sizeof(Grafo::Cjtovertices)/sizeof(Grafo::Cjtovertices[0])){
        if(Grafo::Cjtovertices[i]==""){
            insert = true;
            Grafo::Cjtovertices[i]=n;
        }
        i++;
    }
    
    if(!insert)
        cout << "ERROR: No se pudo insertar el elemento \""<<n<<"\" en el conjunto!" << endl;
}

void Grafo::insertArco(string orgi, string dest, float dist){

}

bool Grafo::pertenece(string n){
    bool found = false;
    int i = 0;
    while (!found && i < sizeof(Grafo::Cjtovertices)/sizeof(Grafo::Cjtovertices[0])){
        if(Grafo::Cjtovertices[i]==n)
            found = true;
        i++;
    }
    return found;
}

float Grafo::Arco(string orig, string dist){
    return .0f;
}

void Grafo::Adyacentes(string nodo, float lista[MAX]){

}

void Grafo::Floyd(){
    
}