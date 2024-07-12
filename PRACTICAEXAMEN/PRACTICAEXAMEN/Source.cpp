¡// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int> &v,const int max) {
    int actual = v[max-1]-v[0]+1;
    int maximo = actual;
    for (int i = max; i < v.size(); i++)
    {
        actual = v[i] - v[i - max + 1] + 1;
        if (actual < maximo) {
            maximo = actual;
        }
    }
    return maximo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, val, max;
    cin >> tamano;
    if (tamano==-1)
        return false;
    vector<bool> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    cin >> max;
    vector<int> aux;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]) {
            aux.push_back(i);
        }
    }
    if (aux.size() < max) {
        cout << aux.size()+1 << "\n";
    }
    else{
        int sol = resolver(aux,max);
        cout << sol << "\n";
    }
    

    // escribir sol

    return true;

}

int main() {


    while (resuelveCaso())
        ;

    return 0;
}
