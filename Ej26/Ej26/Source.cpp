//Miguel Mateos
//A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

// función que resuelve el problema
int resolver(const vector<bool> &v,const int &k) {
    int actual=0;
    int minimo=0;
    int sol = 0;
    vector<int> aux;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1) {
            aux.push_back(i);
        }
    }
    if (aux.size() < k ) {
        sol = v.size() + 1;
    }
    else if (k==aux.size()) {
        sol = aux[k-1] - aux[0] + 1;
    }
    else {
        minimo = aux[k - 1] - aux[0];
        actual = minimo;
        for (int i =k ; i < aux.size(); i++)
        {
            actual -= (aux[i-k+1]-aux[i-k]);
            actual += (aux[i]-aux[i-1]) ;
            if (actual < minimo) {
                minimo = actual;
            }
        }
        sol = minimo + 1;

    }
    







    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,k;
    bool valor;
    vector<bool> v;
    cin >> tamano;
    if (tamano==-1)
        return false;

    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    cin >> k;
    int sol = resolver(v,k);
    cout << sol << "\n";

    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;


    return 0;
}
