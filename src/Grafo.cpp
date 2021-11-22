/**
 * @file Grafo.cpp
 * @author Francisco Javier Ortiz Valverde
 * @author Miguel Martínez Redondo
 * @date 2021-11-22 
 */

#include "Grafo.h"

#define DATOS "Datos.in"

ifstream data;
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

    // Cargar fichero
    cout << "Cargando fichero \"" << DATOS << "\"" << endl;
    data.open(DATOS);
    if (!data)
        cout << "ERROR: No se ha encontrado el fichero " << DATOS << endl;
    else
        cout << "Fichero de datos " << DATOS << " cargado correctamente" << endl;

    this->CargarDatos();
}

void Grafo::CargarDatos()
{
    int n;
    float dist;
    string str1, str2;
    data.seekg(0, ios::beg);

    // Insertar nodos
    data >> n;
    cout << "Cargando (" << n << ") nodos." << endl;
    for (int i = 0; i < n; i++)
    {
        data >> str1;
        this->insertNodo(str1);
        cout << i + 1 << "." << str1 << endl;
    }

    // Insertar arcos
    data >> n;
    cout << "Cargando (" << n << ") arcos." << endl;
    for (int i = 0; i < n; i++)
    {
        data >> str1;
        data >> str2;
        data >> dist;
        cout << i + 1 << ". " << str1 << " - " << str2 << " : " << dist << endl;
        this->insertArco(str1, str2, dist);
    }
}

void Grafo::ejecutarConsultas(){
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
        this->Camino(s1, s2);
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

void Grafo::Camino(string orig, string dest)
{
    pair<int, int> index = this->getIndex(orig, dest);
    cout << this->Cjtovertices[index.first] << " ";
    file << this->Cjtovertices[index.first] << " ";
    CaminoInt(index.first, index.second);
    cout << this->Cjtovertices[index.second] << " " << this->MatFloyd[index.first][index.second] << endl;
    file << this->Cjtovertices[index.second] << " " << this->MatFloyd[index.first][index.second] << endl;
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