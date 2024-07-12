// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema

int sumaDigitos(int n) {
    if (n < 10) {
        return n;
    }
    else {
        return sumaDigitos(n / 10) + n%10;
    }

}
vector<int> resolver(const vector<int> &v,const int &k) {
    vector<int> sol;
    int aux = sumaDigitos(k);

    for (int i = 0; i < v.size(); i++)
    {
        if (aux == sumaDigitos(v[i])) {
            sol.push_back(v[i]);
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int tamano, k,valor ;
    vector<int> v;
    cin >> tamano;
    cin >> k;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    vector<int> sol = resolver(v,k);

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
    // escribir sol


}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}