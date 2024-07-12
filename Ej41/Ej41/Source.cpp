// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> v1,vector <int> v2,int ini,int fin) {
    if (ini == fin) {
        return 0;
    }
    else if (ini+1 == fin) {
        return ini + 1;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v2[mitad]<=v1[mitad]) {
            return resolver(v1,v2,mitad,fin);
        }
        else {
            return resolver (v1,v2,ini,mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    vector<int> v1;
    vector<int> v2;
    cin >> tamano;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v1.push_back(valor);
    }
    for (int i = 0; i < tamano-1; i++)
    {
        cin >> valor;
        v2.push_back(valor);
    }
   
    int sol = resolver(v1,v2,0,v2.size());
    if (v2.size() != 0 && v1[sol]==v2[0]) {
        sol--;
    }
    cout << v1[sol] << "\n";
    // escribir sol


}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}