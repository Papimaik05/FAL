// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int aux(int n, int cuenta,int pot) {
    if (n % 2 == 0) {
        if (n < 10) {
            return ((n+1)*pot) + cuenta;
        }
        else {
            return aux(n / 10, ((n % 10) + 1) * pot + cuenta,pot*10);
        }
    }
    else {
        if (n < 10) {
            return ((n - 1) * pot) + cuenta;
        }
        else {
            return aux(n/10,((n % 10) -1) * pot + cuenta,pot*10);
        }
    }
}
int resolver(int n) {
    return aux(n, 0, 1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int valor;
    cin >> valor;

    int sol = resolver(valor);

    cout << sol << "\n";


    // escribir sol


}

int main() {
    // Para la entrada por fichero


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}