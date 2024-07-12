// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
vector <int> resolver(const vector<int> &v,int maximo) {
    vector<int> auxiliar(maximo+1,0);


    vector<int> sol;
    for (int i = 0; i < v.size(); i++)
    {
        auxiliar[v[i]]++;
    }

    int max = auxiliar[0];
    for (int i = 1; i < auxiliar.size(); i++)
    {
        if (auxiliar[i] > max) {
            max = auxiliar[i];
        }
    }
    for (int i = auxiliar.size()-1 ; i > 0; i--)
    {
        if (max == auxiliar[i]) {
            sol.push_back(i);
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int tamano,max,valor;
    vector<int> v;
    cin >> tamano;
    if (tamano==-1)
        return false;
    cin >> max;

    for (int i  = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    

    vector<int> sol = resolver(v,max);

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}
