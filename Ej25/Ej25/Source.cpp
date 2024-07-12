// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
// función que resuelve el problema
int resolver(const vector<int> &v,const int &entrada,int &sol1,int &sol2) {
    int suma=0;
    int veces = 1;
    int maximo=0;

    for (int i = 0; i < entrada; i++)
    {
        suma += v[i];
    }
    maximo = suma;
    for (int i = entrada; i < v.size(); i++)
    {
        suma -= v[i-entrada];
        suma += v[i];
        if (suma>maximo) {
            maximo = suma;
            sol1 = i - entrada + 1;
            veces = 1;
        }
        else if (suma == maximo) {
            veces++;
            sol2 = i - entrada + 1;
        }
    }
    if (veces == 1) {
        sol2 = sol1;
    }
    return maximo;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, longitud,valor;
    vector<int> v;
    cin >> tamano;
    cin >> longitud;
    if (tamano==0 && longitud==0)
        return false;

    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int i = 0;
    int j = 0;
    int sol = resolver(v,longitud,i,j);

    cout << sol << " " << i << " " << j << "\n";

    // escribir sol

    return true;

}

int main() {


    while (resuelveCaso())
        ;

    return 0;
}
