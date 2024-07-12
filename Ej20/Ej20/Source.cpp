// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(const vector<int> &v,int paginas) {
    int suma = 0;
    int pos=0;
    for (int i = 0; i < paginas; i++)
    {
        suma += v[i];
    }
    int sumaMax = suma;
    for (int i = paginas; i < v.size(); i++)
    {
        suma += v[i];
        suma -= v[i - paginas];
        if (suma >= sumaMax) {
            sumaMax = suma;
            pos = i - paginas + 1;
        }

    }
    return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, paginas, valor;
    vector<int>v;
    cin >> tamano;
    cin >> paginas;
    if (tamano==0 && paginas==0)
        return false;

    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int sol = resolver(v, paginas);
    cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

    while (resuelveCaso())
        ;

    return 0;
}
