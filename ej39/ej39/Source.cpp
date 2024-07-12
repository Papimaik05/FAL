// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> &v,int ini,int fin) {

    if (ini + 1 == fin) {
        return v[ini];
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad - 1] > v[mitad]) {
            return resolver(v, mitad, fin);
        }
        else{
            return resolver(v, ini, mitad);
      }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    vector<int> v;

    cin >> tamano;
    if (!std::cin)
        return false;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int sol = resolver(v,0,v.size());

    cout << sol << "\n";

    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}