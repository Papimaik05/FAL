// Miguel Mateos
//A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
vector<int> resolver(vector<int>& v1, vector<int>& v2) {
    vector<int> aux;
    int i = 0;
    int j = 0;
    int size1 = v1.size();
    int size2 = v2.size();

    if (size1 == 0) {
        return v2;
    }
    if (size2 == 0) {
        return v1;
    }

    while (i < size1 || j < size2) {
        if (i == size1) {
            aux.push_back(v2[j]);
            j++;
        }
        else if (j == size2) {
            aux.push_back(v1[i]);
            i++;
        }
        else if (v1[i]==v2[j]) {
            aux.push_back(v1[i]);
            aux.push_back(v2[j]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j]) {
            aux.push_back(v1[i]);
            i++;
        }
        else if (v2[j] < v1[i]) {
            aux.push_back(v2[j]);
            j++;
        }
    }

    return aux;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int tamano1, tamano2;
    cin >> tamano1;
    cin >> tamano2;
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < tamano1; i++)
    {
        int valor;
        cin >> valor;
        v1.push_back(valor);
    }

    for (int i = 0; i < tamano2; i++)
    {
        int valor;
        cin >> valor;
        v2.push_back(valor);
    }
    vector<int> sol = resolver(v1, v2);
    int size = sol.size();
    for (int i = 0; i < size; i++)
    {
        cout << sol[i] << "  ";
    }
    cout << "\n";


}

int main() {



    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    return 0;
}