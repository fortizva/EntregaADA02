#include "Grafo.h"

Grafo::Grafo()
{
    cout << "Inicializando Grafo" << endl;
    this->ocupados = 0;
    for (int i = 0; i < Grafo::MAX; i++)
    {
        this->Cjtovertices[i] = "";
        for (int j = 0; j < Grafo::MAX; j++)
        {
            this->MatAdyacencia[i][j] = (i == j) ? 0 : 9999;
        }
    }
}

void Grafo::insertNodo(string n)
{
    if (!this->ocupados >= Grafo::MAX)
    {
        this->Cjtovertices[ocupados] = n;
        this->ocupados++;
    }
    else
        cout << "ERROR: No se pudo insertar el elemento \"" << n << "\" en el conjunto!" << endl;
}

void Grafo::insertArco(string orgi, string dest, float dist)
{
}

bool Grafo::pertenece(string n)
{
    bool found = false;
    int i = 0;
    while (!found && i < this->ocupados)
    {
        if (this->Cjtovertices[i] == n)
            found = true;
        i++;
    }
    return found;
}

float Grafo::Arco(string orig, string dist)
{
    return .0f;
}

void Grafo::Adyacentes(string nodo, float lista[MAX])
{
}

void Grafo::Floyd()
{
    // Copiamos la matriz de adyacencia en C
    for (int i = 0; i < Grafo::MAX; i++)
        for (int j = 0; j < Grafo::MAX; j++)
            this->MatFloyd[i][j] = this->MatAdyacencia[i][j];

    for (int k = 0; k < Grafo::MAX; k++)
        for (int i = 0; i < Grafo::MAX; i++)
            for (int j = 0; j < Grafo::MAX; j++)
                if ((this->MatFloyd[i][k] + this->MatFloyd[k][j]) < this->MatFloyd[i][j])
                {
                    this->MatFloyd[i][j] = this->MatFloyd[i][k] + this->MatFloyd[k][j];
                    this->MatP[i][j] = k;
                }
}

void Grafo::Camino(int i, int j)
{
    int k;
    k = this->MatP[i][j];
    if (k != 0)
    {
        Camino(i, k);
        cout << k << ";" << endl;
        Camino(k, j);
    }
}
