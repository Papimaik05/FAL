// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void escribirvector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0) {
            cout << "azul ";
        }
        else if (v[i] == 1) {
            cout << "rojo ";
        }
        else if (v[i] == 2) {
            cout << "verde ";
        }
    }
}
// función que resuelve el problema
void resolver(int n,int m,int k,vector<int> &v) {
    for (int i = 0; i < n; i++)
    {
        v[k] = i;
        if (k == m - 1) {
            escribirvector(v);
            cout << "\n";
        }
        else {
            resolver(n, m, k + 1, v);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    cin >> tamano;
    if (tamano==0)
        return false;

    vector<int> v(tamano);
    resolver(3,tamano,0,v);

    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;
    return 0;
}
