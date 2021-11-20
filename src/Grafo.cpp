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
    if (this->ocupados < Grafo::MAX)
    {
        this->Cjtovertices[ocupados] = n;
        this->ocupados++;
    }
    else
        cout << "ERROR: No se pudo insertar el elemento \"" << n << "\" en el conjunto!" << endl;
}

void Grafo::insertArco(string orig, string dest, float dist)
{
    // Obtener los índices de origen y destino
    if (this->pertenece(orig) && this->pertenece(dest))
    {
        int i = 0, orig_i = -1, dest_i = -1;

        while (i < this->ocupados && (orig_i == -1 || dest_i == -1))
        {
            orig_i = (orig == this->Cjtovertices[i]) ? i : orig_i;
            dest_i = (dest == this->Cjtovertices[i]) ? i : dest_i;
            i++;
        }

        this->MatAdyacencia[orig_i][dest_i] = dist;
        this->MatAdyacencia[dest_i][orig_i] = dist;
    }
    else
        cout << "ERROR: Una de las ciudades \"" << orig << "\" o \"" << dest << "\" no existe!" << endl;
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

float Grafo::Arco(string orig, string dest)
{
    float dist = 9999;
    // Obtener los índices de origen y destino
    if (this->pertenece(orig) && this->pertenece(dest))
    {
        int i = 0, orig_i = -1, dest_i = -1;

        while (i < this->ocupados && (orig_i == -1 || dest_i == -1))
        {
            orig_i = (orig == this->Cjtovertices[i]) ? i : orig_i;
            dest_i = (dest == this->Cjtovertices[i]) ? i : dest_i;
            i++;
        }
        dist = this->MatAdyacencia[orig_i][dest_i];
    }
    else
        cout << "ERROR: Una de las ciudades \"" << orig << "\" o \"" << dest << "\" no existe!" << endl;
    return dist;
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
    cout << "MATRIZ FLOYD"<<endl;
    this->MostrarDatos(this->MatFloyd);
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

void Grafo::MostrarDatos(float matriz[Grafo::MAX][Grafo::MAX])
{
    for (int i = 0; i < Grafo::MAX; i++)
    {
        for (int j = 0; j < Grafo::MAX; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}