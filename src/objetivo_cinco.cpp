/*

    Objetivo 5: Floyd-Warshall
    ====================================

    Una empresa decide centralizar los servicios de hosting en una de sus sedes.
    
    Para comunicarse con el resto de oficinas, el departamento de comunicaciones 
    se plantea desplegar una red, para lo que estima los costes que aparecen en la matriz adjunta.

    Realice un programa en C++ para encontrar, aplicando el algoritmo de Floyd-Warshall,
    las rutas que deberia utilizar S (nodo central), para comunicarse con
    todas las sedes. Si se sigue asumiendo que la tasa de generaci´on de paquetes es la misma para 
    todas las oficinas,

*/

#include "data_structures.h"
#include "algoritmos.h"
#include <climits>
#include <iostream>
#include <vector>
using namespace std;


void objetivoCinco()
{
    
    // matriz de costos
    vector<vector<int>>costs =
    {
        {0, 3, 8, 9},
        {3, 0, 7, 6},
        {8, 7, 0, 2},
        {9, 6, 2, 0}
    };

    // imprimir la matriz de costos
    cout << "matriz de costos: " << endl;
    for (int i = 0; i < costs.size(); i++)
    {
        for (int j = 0; j < costs[i].size(); j++)
        {
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "ejecutando el algoritmo de Floyd-Warshall..." << endl;
    alg::floydWarshall(costs);
    cout << "algoritmo de Floyd-Warshall ejecutado" << endl;

    cout << "matriz de costos mas cortos: " << endl;
    for (int i = 0; i < costs.size(); i++)
    {
        for (int j = 0; j < costs[i].size(); j++)
        {
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "fin de la matriz de costos mas cortos" << endl;

    // calcular el promedio de enlaces
    double totalEnlaces = 0;
    int totalPares = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        for (int j = 0; j < costs[i].size(); j++)
        {
            if (i != j && costs[i][j] != INT_MAX)
            {
                totalEnlaces += costs[i][j];
                totalPares++;
            }
        }
    }
    double promedioEnlaces = totalEnlaces / totalPares;
    cout << "ll promedio de enlaces es: " << promedioEnlaces << endl;

    cout << "fin del promedio de enlaces" << endl;

    cout << "fin del objetivo 5" << endl;

}