#include <iostream>
#include <fstream>

#include "Grafo.h"

#define DATOS "Datos.in"

using namespace std;

void loadData(ifstream *data, Grafo *g)
{
    int n;
    float dist;
    string str1, str2;
    data->seekg(0, ios::beg);

    // Insertar nodos
    *data >> n;
    cout << "Cargando (" << n << ") nodos." << endl;
    for (int i = 0; i < n; i++)
    {
        *data >> str1;
        g->insertNodo(str1);
        cout << i+1 << "." << str1 << endl;
    }

    // Insertar arcos
    *data >> n;
    cout << "Cargando (" << n << ") arcos." << endl;
    for (int i = 0; i < n; i++)
    {
        *data >> str1;
        *data >> str2;
        *data >> dist;
        cout << i+1 << ". " << str1 << " - " << str2 << " : " << dist << endl;
        g->insertArco(str1, str2, dist);
    }
}

int main()
{
    cout << "Hello World!" << endl;
    // Cargar fichero
    ifstream data;
    data.open(DATOS);
    if (!data)
        cout << "ERROR: No se ha encontrado el fichero " << DATOS << endl;
    else
        cout << "Fichero de datos " << DATOS << " cargado correctamente" << endl;

    // Crear grafo
    Grafo g;
    loadData(&data, &g);
    g.Floyd();

    return 0;
}