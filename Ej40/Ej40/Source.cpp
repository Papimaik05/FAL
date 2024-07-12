// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
// funcio?n que resuelve el problema
char resolver(vector<char> v,int ini,int fin) {
    if (ini == fin) {
        return 0;
    }
    if (ini + 1 == fin) {
        return v[ini] + 1;
    }
    else {
        int mitad = (ini + fin ) / 2;
        if (v[mitad] - v[ini] == mitad - ini) {
            return resolver(v,mitad,fin);
        }
        else {
            return resolver(v,ini,mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char char1, char2,valor;
    vector<char> v;
    cin >> char1;
    cin >> char2;
    for (int i = 0; i < char2-char1; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    char sol = resolver(v,0,v.size());

    if (sol == char2 + 1) {
        sol = char1;
    }

    cout <<  sol << "\n";
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}