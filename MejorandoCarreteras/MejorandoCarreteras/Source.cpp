// Miguel Mateos
// A50


#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver( vector<int>&v) {
    sort(v.begin(),v.end());
    int actual = 1; 
    int maximo=1;
    int sol=v[0];

    if (v.size() == 1) {
        sol = v[0];
    }
    else {
        for (int i = 1; i < v.size(); i++) //coste n (siendo n el tamano del vector)
        {
            if (v[i] == v[i - 1]) {
                actual++;
                if (actual > maximo) {
                    maximo = actual;
                    sol = v[i];
                }
            }
            else {
                actual = 1;
            }
        }
    } 
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int valor;
    long long int tamano;
    vector<int> v;
    cin >> tamano;
 
    if (tamano==-1)
        return false;

    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int sol = resolver(v);

    cout << sol << "\n";
    // escribir sol

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}
