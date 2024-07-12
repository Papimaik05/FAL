// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
bool resolver(const vector<int> &v,int disp,int ini,int fin) {
    if (ini + 1 == fin) {
        return true;
    }
        int mitad = (ini + fin) / 2;
        return abs(v[fin - 1] - v[ini]) >= disp && resolver(v, disp, ini, mitad) && resolver(v, disp, mitad, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    long long disp;
    cin >> tamano;
    cin >> disp;
    if (!std::cin)
        return false;

    long long valor;
    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    bool sol = resolver(v,disp,0,v.size());
    if (sol) {
        cout << "SI \n";
    }
    else {
        cout << "NO \n";
    }

    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}