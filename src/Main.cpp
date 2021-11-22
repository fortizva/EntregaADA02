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
        cout << i + 1 << "." << str1 << endl;
    }

    // Insertar arcos
    *data >> n;
    cout << "Cargando (" << n << ") arcos." << endl;
    for (int i = 0; i < n; i++)
    {
        *data >> str1;
        *data >> str2;
        *data >> dist;
        cout << i + 1 << ". " << str1 << " - " << str2 << " : " << dist << endl;
        g->insertArco(str1, str2, dist);
    }
}

int main()
{
    // Cargar fichero
    ifstream data;
    cout << "Cargando fichero \"" << DATOS << "\"" << endl;
    data.open(DATOS);
    if (!data)
        cout << "ERROR: No se ha encontrado el fichero " << DATOS << endl;
    else
        cout << "Fichero de datos " << DATOS << " cargado correctamente" << endl;

    // Crear grafo
    Grafo g;
    loadData(&data, &g);

    // Algoritmo de Floyd
    cout << endl;
    g.Floyd();

    // Ejecutar las consultas
    int num = 0;
    string s1, s2;
    pair<int, int> index;
    data >> num;

    for (int i = 0; i < num; i++)
    {
        data >> s1;
        data >> s2;
        cout << s1 << " - " << s2 << ": " << endl
             << "\t";
        index = g.getIndex(s1, s2);
        g.Camino(index.first, index.second);
    }

    return 0;
}