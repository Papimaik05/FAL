// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(const vector<int> &v) {
    int actual = 1;
    int i = 1;
    int maximo = 0;
    int contador = 1;
    if (v.size() <= 1) {
        return v.size();
    }
    while (i < v.size()) {

        if (v[i] <= v[i - 1]) {
            actual++;
            contador = 1;
        }
        else {
            contador++;  
            if (contador == 3) {
                contador = 2;
                //i--;
                actual = 2;
            }
            else {
                actual++;
            }
            
        }

        if (actual > maximo) {
            maximo = actual;
        }
        i++;
    }
    return maximo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamano, valor;
    cin >> tamano;
    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int sol = resolver(v);
    cout << sol << "\n";
    // escribir sol


}

int main() {


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();




    return 0;
}