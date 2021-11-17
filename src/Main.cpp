#include <iostream>
#include <fstream>

#include "Grafo.h"

#define DATOS "Datos.in"

using namespace std;

int main(){
    cout << "Hello World!" << endl;
    // Cargar fichero
    ifstream data;
    data.open(DATOS);
    if(!data)
        cout <<"ERROR: No se ha encontrado el fichero "<< DATOS <<endl;
    // Crear grafo
    Grafo g;

    return 0;
}