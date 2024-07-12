// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
pair<int,int> resolver(vector<int> &v,const int &mediano,const int &grande) {
    int i = 0;
    int k = 0;
    int j = v.size() - 1;

    while (k <= j) {
        if (v[k] >= mediano && v[k] < grande) {
            k++;
        }
        else if (v[k] < mediano) {
            swap(v[k], v[i]);
            i++;
            k++;
        }
        else if (v[k] >= grande) {

            swap(v[k], v[j]);
            j--;
        }
    }
    sort(v.begin(), v.begin()+i);
    sort(v.begin() + i, v.begin()+k);
    sort(v.begin()+k,v.end());
    return{i,k};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, mediano, grande,valor;
    vector<int> v;
    cin >> tamano;
    cin >> mediano;
    cin >> grande;
    if (!std::cin)
        return false;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    pair<int,int> sol=resolver(v,mediano,grande);

    // escribir sol
    for (int i = 0; i < sol.first; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    for (int i = sol.first; i < sol.second; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    for (int i = sol.second; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    cout << "---" << "\n";
    return true;

}

int main() {


    while (resuelveCaso())
        ;

    return 0;
}