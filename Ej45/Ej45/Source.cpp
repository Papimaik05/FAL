// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// función que resuelve el problema
pair<string, int>  resolver(const vector<pair<string, int>> &v,int ini,int fin) {
    if (ini+2==fin) {
        if (v[ini].second >= v[ini + 1].second) {
            return {v[ini].first,v[ini].second + (v[ini + 1].second / 2) };
        }
        else {
            return { v[ini+1].first,v[ini+1].second + (v[ini].second / 2) };
        }
    }
    else {
        int mitad = (ini + fin) / 2;
        pair<string, int> sol1 = resolver(v,ini,mitad);
        pair<string, int> sol2 = resolver(v, mitad, fin);
        if (sol1.second >= sol2.second) {
            return { sol1.first,sol1.second + (sol2.second / 2) };
        }
        else {
            return { sol2.first,sol2.second + (sol1.second / 2) };
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    cin >> tamano;
    if (!std::cin)
        return false;
    string nombre;
    int canicas;
    vector<pair<string, int>> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> nombre;
        cin >> canicas;
        v.push_back(pair<string, int>(nombre, canicas));
    }

    pair<string, int> sol = resolver(v,0,v.size());
    cout << "\n";
    cout << sol.first << "  " << sol.second << "\n";
    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}