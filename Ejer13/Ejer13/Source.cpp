// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
pair<int,int> resolver(const vector <int> &v,int altura) {
    int actual = 0;
    int maximo = 0;
    int final = 0;
    for (int i = 0; i < v.size(); i++) //coste n(siendo n el numero de elementos)
    {
        if (v[i] > altura) {
            actual++;
            if (actual > maximo) {
                maximo = actual;
                final = i;
            }
        }
        else {
            actual = 0;
           
        }
    }
    int inicio = final - maximo + 1;
    return {inicio,final};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    int altura;
    cin >> tamano;
    cin >> altura;
    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    pair<int,int> sol = resolver(v,altura);
    cout << sol.first << " " << sol.second << "\n";
    // escribir sol


}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}