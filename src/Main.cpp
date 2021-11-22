/**
 * @file Main.cpp
 * @author Francisco Javier Ortiz Valverde
 * @author Miguel Martínez Redondo
 * @date 2021-11-22 
 */

#include <iostream>
#include <fstream>

#include "Grafo.h"

using namespace std;

int main()
{

    // Crear grafo
    Grafo g;

    // Algoritmo de Floyd
    cout << endl;
    g.Floyd();

    // Ejecutar las consultas
    g.ejecutarConsultas();

    return 0;
}