// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int> &v,const int &superar,int &secuencia,int &veces) {
    int maximo = v[v.size() - 1];
    int actual=1;
    vector<int>sol;
    for (int i = v.size()-2; i >= 0; i--)
    {
        if (v[i]>=maximo) {
            maximo = v[i];
            if (v[i] == v[i + 1]) {
                actual++;
                if (actual == superar) {
                    veces++;
                    sol.push_back(i+actual-1);
                    if (secuencia == 0) {
                        secuencia = superar;
                    }
                    
                }
                if (actual > secuencia && secuencia!=0) {
                    secuencia = actual;
                }
            }
            else {
                actual=1;
            }
        }
        else {
            actual = 1;
        }
        
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    cin >> tamano;
    if (!std::cin)
        return false;
    int longitud;
    cin >> longitud;
    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int secuencia=0,veces=0;
    vector<int> sol = resolver(v,longitud,secuencia,veces);

    // escribir sol
    cout << secuencia << " " << veces << " ";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

    while (resuelveCaso())
        ;




    return 0;
}