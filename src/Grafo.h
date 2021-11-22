/**
 * @file Grafo.h
 * @author Francisco Javier Ortiz Valverde
 * @author Miguel Martínez Redondo
 * @date 2021-11-22 
 */


#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Grafo
{
	static const int MAX = 20; //Constante de valor 20, es de utilidad ya que se indica que como máximo tedremos 14 + 6 nodos.

	int ocupados; // Contador de nodos presentes en el conjunto.

	string Cjtovertices[MAX]; //Conjunto de nodos (vértices) que tendrá nuestro Grafo

	float MatAdyacencia[MAX][MAX]; //Conjunto de aristas valuadas  que tendrá nuestro Grafo, (Matriz de Adyacencia)

	float MatFloyd[MAX][MAX]; // Matriz en la que se refleja el resultado del algoritmo de Floyd-Warshall.

	int MatP[MAX][MAX]; // Matriz que contiene las rutas entre nodos tras el algoritmo de Floyd-Warshall.

public:
	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas}
	 * POST: {-Inicializamos el numero de ocupados 0
     *  	  -Inicializamos el conjunto de vértices
     *        -Inicializamos el conjunto de caminos (Matriz de Adyacencia) con el valor 9999 en todas sus casillas y 0 en la diagonal,
	 *        }
	 * Complejidad: O(n^2)
	 */
	Grafo();

	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas e inicializadas}
	 * POST: {Abrimos un flujo de lectura del fichero "Datos.in" y cargamos las diferentes estructuras del Grafo a partir de los datos ...............}
	 * 
	 * 
	 * Complejidad: O(n)
	 */
	void CargarDatos();

	/*
	 * PRE: {Las estructuras del grafo han de estar correctamente definidas e inicializadas, el grafo debe haber sido rellenado con los datos del fichero y el algoritmo de Floyd-Warshall debe haber sido ejecutado previamente}
	 * POST: {Ejecuta las consultas del fichero sobre los datos obtenidos del algoritmo de Floyd-Warshall}
	 * 
	 * Complejidad: O(n)
	 */
	void ejecutarConsultas();

	/*
	 * PRE: {El vector del conjunto de nodos debe estar correctamente definidas e inicializadas y debe haber espacio disponible en el vector de conjuntos}
	 * POST: {Insertamos el nodo en el vector del conjunto y aumentamos el contador de nodos}
	 * 
	 * Complejidad: O(1)
	*/
	void insertNodo(string n);

	/*
	 * PRE: {Tanto el vector del conjunto de nodos como la matriz de adyacencia han de estar correctamente definidos e inicializados, tanto el origen como el destino deben existir en el vector de conjuntos y la distancia debe ser igual o mayor a cero}
	 * POST: {Introducimos la distancia del arco entre ambos nodos en la matriz de adyacencia}
	 * 
	 * Complejidad: O(n)
	 */
	void insertArco(string orig, string dest, float dist);

	/*
	 * PRE: {El vector del conjunto de nodos debe estar correctamente definido e inicializado}
	 * POST: {Devuelve verdadero si el nodo existe en el vector del conjunto, en caso contrario, devuelve falso}
	 * 
	 * Complejidad: O(n)
	 */
	bool pertenece(string n);

	/*
	 * PRE: {La matriz de adyacencia y el vector de conjunto de nodos deben estar correctamente definidos e inicializados y tanto el origen como el destino deben pertencer a este último}
	 * POST: {Devuelve el valor del arco entre el nodo origen y destino, de no existir arco entre ambos, devuelve 99999}
	 * 
	 * Complejidad: O(n)
	 */
	float Arco(string orig, string dist);
	
	/*
	 * PRE: {Las estructuras del grafo deben estar correctamente definidas e inicializadas}
	 * POST: {Aplica el algoritmo de Floyd-Warshall usando las estructuras del grafo}
	 * 
	 * Complejidad: O(n^3)
	 */
	void Floyd();

	/*
	 * PRE: {El conjunto de vértices y la matriz de rutas deben estar correctamente definidos e inicializadas, ambos nodos deben pertenecer al vector del conjunto y ha de haberse ejecutado el algoritmo de Floyd-Warshall previamente}
	 * POST: {Muestra los nodos que conforman la ruta más corta entre los nodos dados}
	 * 
	 * Complejidad: O(n)
	 */
	void Camino(string orig, string dest);
	
	/*
	 * PRE: {El vector del conjunto de nodos debe estar correctamente definido e inicializado y ambos nodos deben pertenecer a dicho vector}
	 * POST: {Devuelve el índice sobre el vector del conjunto de nodos del origen y destino}
	 * 
	 * Complejidad: O(n)
	 */
	pair<int, int> getIndex(string orig, string dest);
	// ...

	/*
	 * PRE: {La estructuras del grafo han de estar correctamente definidas, inicializadas y cargadas}
	 * POST: {Muestra la matriz que se indica como parámetro de entrada.
	 * Complejidad: O(n^2)
	 */
	void MostrarDatos(float matriz[MAX][MAX]);

private:
/*
 * PRE: {El conjunto de vértices y la matriz de rutas deben estar correctamente definidos e inicializadas, ambos nodos deben pertenecer al vector del conjunto y ha de haberse ejecutado el algoritmo de Floyd-Warshall previamente}
 * POST:{Muestra de forma recursiva la ruta intermedia entre dos nodos}
 * 
 * Complejidad: O(n)
 */
	void CaminoInt(int i, int j);
};

#endif /* GRAFO_H_ */
