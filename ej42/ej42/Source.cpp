// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

// función que resuelve el problema
int resolver(vector<int> v,int cantado,int ini,int fin) {
    if (ini + 1 == fin) {
        return ini;
    }
    else {
    int mitad = (ini + fin) / 2;
    if (mitad+cantado < v[mitad]) {
        return resolver(v,cantado,ini,mitad);
    }
    else {
        return resolver(v, cantado,mitad,fin);
    }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamano, cantado, valor;
    vector<int> v;

    cin >> tamano;
    cin >> cantado;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int sol = resolver(v,cantado,0,v.size());

    if (v[sol] != sol + cantado) {
        cout << "NO" << "\n";
    }
    else {
        cout << v[sol] << "\n";
    }
    // escribir sol


}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    return 0;
}