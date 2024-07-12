// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string aux(int n, string cuenta) {
    if (n == 0) {
        return "0"+ cuenta;
    }
    else if (n == 1) {
        return "1" + cuenta ;
    }
    else {
        return  aux(n / 2,to_string(n % 2) + cuenta );
    }

}
// función que resuelve el problema
string resolver(int n) {
    return aux(n, "");
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