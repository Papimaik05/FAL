// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
// funcion que resuelve el problema
int resolver(vector <int> &v,int ini , int fin) {
    if (ini + 1 == fin) {
        return 0;
    }
    else {
        int mitad = (ini + fin) / 2;
        int Izda = resolver(v,ini,mitad);
        int Drcha = resolver(v,mitad,fin);
        int i = ini; int j = (ini + fin) / 2;
        int aux = 0;
        while (i < mitad && j < fin) {
            if (v[j] < v[i]) {
                aux += (mitad - i);
                j++;
            }
            else {
                i++;
            }
        }
        inplace_merge(v.begin() + ini, v.begin() + mitad, v.begin() + fin);
        return Izda + Drcha + aux;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    cin >> tamano;
    if (!std::cin)
        return false;
    vector<int> v;
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