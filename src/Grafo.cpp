#include "Grafo.h"

ofstream file;

Grafo::Grafo()
{
    file.open("datos.out");
    cout << "Inicializando Grafo" << endl;
    this->ocupados = 0;
    for (int i = 0; i < Grafo::MAX; i++)
    {
        this->Cjtovertices[i] = "";
        for (int j = 0; j < Grafo::MAX; j++)
        {
            this->MatAdyacencia[i][j] = (i == j) ? 0 : 9999;
            this->MatP[i][j] = -1;
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
    pair<int, int> index = getIndex(orig, dest);
    this->MatAdyacencia[index.first][index.second] = dist;
    this->MatAdyacencia[index.second][index.first] = dist;
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
    pair<int, int> index = getIndex(orig, dest);
    float dist = this->MatAdyacencia[index.first][index.second];
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
    cout << "MATRIZ FLOYD" << endl;
    this->MostrarDatos(this->MatFloyd);
}

void Grafo::Camino(int i, int j)
{
    cout << this->Cjtovertices[i] << " ";
    file << this->Cjtovertices[i] << " ";
    CaminoInt(i, j);
    cout << this->Cjtovertices[j] << " " << this->MatFloyd[i][j] << endl;
    file << this->Cjtovertices[j] << " " << this->MatFloyd[i][j] << endl;
}

void Grafo::CaminoInt(int i, int j)
{
    int k;
    k = this->MatP[i][j];
    if (k != -1)
    {
        CaminoInt(i, k);
        cout << Cjtovertices[k] << " ";
        file << Cjtovertices[k] << " ";
        CaminoInt(k, j);
    }
}

pair<int, int> Grafo::getIndex(string orig, string dest)
{
    int i = 0, orig_i = -1, dest_i = -1;
    // Obtener los índices de origen y destino
    if (this->pertenece(orig) && this->pertenece(dest))
    {

        while (i < this->ocupados && (orig_i == -1 || dest_i == -1))
        {
            orig_i = (orig == this->Cjtovertices[i]) ? i : orig_i;
            dest_i = (dest == this->Cjtovertices[i]) ? i : dest_i;
            i++;
        }
    }
    else
        cout << "ERROR: Una de las ciudades \"" << orig << "\" o \"" << dest << "\" no existe!" << endl;

    return make_pair(orig_i, dest_i);
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