// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// función que resuelve el problema
string resolver(int n) {
    if (n == 0) {
        return "0";
    }
    else if (n == 1) {
        return "1";
    }
    else {
        int aux = n % 2;
        return  resolver(n / 2) + to_string(aux);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int valor;
    cin >> valor;
    string sol = resolver(valor);
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