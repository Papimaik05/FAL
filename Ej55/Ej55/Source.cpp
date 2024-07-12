// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(const vector<int> &v,vector<vector<int>>& matriz,int suma,int valores) {
    if (suma==0) {
        return 1;
    }
    else if (valores==0 && suma>0) {
        return 0;
    }
    else if (valores == 1 && suma > 0) {
        if (v[0] == suma) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {

        return resolver(v, matriz, suma, valores - 1) + resolver(v,matriz,suma-v[valores],valores-1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, sumas;
    cin >> tamano;
    cin >> sumas;
    if (!std::cin)
        return false;
    vector<int> v;
    int valor;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    vector<vector<int>> matriz(tamano + 1, vector<int>(tamano+1, -1));
    int sol = resolver(v,matriz,sumas,tamano-1);

    cout << sol << "\n";
    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}