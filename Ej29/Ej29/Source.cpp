// Miguel Mateos
//A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int> &v,const int &k) {
    int contadorpares = 0;
    int actual = 0;
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        
        if ((v[i] % 2) ==0) {
            contadorpares++;
            if (contadorpares > k) {
                contadorpares--;
                actual = k;
            }
            else {
                actual++;
            }
        }
        else {
            actual++;
            contadorpares = 0;
        }

        if (actual > max) {
            max = actual;
        }
    }

    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamano, k,valor;
    vector<int> v;
    cin >> tamano;
    cin >> k;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int sol = resolver(v,k);

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