// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void resolver(const vector<int> &v,int &sol1,int &sol2) {
    int batir = v[0];
    int longitud = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > batir) {
            batir = v[i];
            longitud = 0;
        }
        else {
            longitud++;
            if (longitud >= sol1) {
                sol1 = longitud;
                sol2 = i - longitud+1;
            }

        }
    }

    if (sol2==0) {
        sol2 = v.size();
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    vector<int>v;
    cin >> tamano;
    if (tamano==0)
        return false;

    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int maximo=0;
    int desde=0;
    resolver(v,maximo,desde);

    cout << maximo << "  " << desde << "\n";
    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el re

    while (resuelveCaso())
        ;

    return 0;
}
