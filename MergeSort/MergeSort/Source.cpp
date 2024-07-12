// Miguel Mateos 
// A50

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// función que resuelve el problema
void mergesort(vector<int>& v, int ini, int fin) {
    if (ini + 1 < fin) {
        int mitad = (ini + fin) / 2;
        mergesort(v, ini, mitad);
        mergesort(v, mitad, fin);
        inplace_merge(v.begin() + ini, v.begin() + mitad, v.begin() + fin);
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

    mergesort(v,0,v.size());
    if (v.size() != 0) {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    cout << "\n";
    

    // escribir sol


    return true;

}

int main() { 

    while (resuelveCaso())
        ;


    return 0;
}