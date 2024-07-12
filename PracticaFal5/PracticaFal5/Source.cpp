// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;
// función que resuelve el problema
int resolver(const vector<int> &v,const int &k) {
    int sol = 0;
    int vizda = 0;
    int vderecha = 0;

    for (int i = 0; i < k/2; i++) //coste k (siendo k el tamano del intervalo)
    {
        if (v[i] > 0) {
           vizda++;
        }
    }
    for (int i = k/2; i < k; i++)
    {
        if (v[i] > 0) {
            vderecha++;
        }
    }
    if (vizda >= vderecha) { //coste cte
        sol++;
    }


    for (int i = k; i < v.size(); i++) // coste n siendo n= v.size()-k
    {
        if (v[i] > 0) {
            vderecha++;
        }
        if (v[i - k] > 0) {
            vizda--;
        }

        if (v[i - k/2] > 0) {
            vderecha--;
            vizda++;
        }


        if (vizda >= vderecha) {
            sol++;
        }
    }
   

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, k, valor;
    vector<int> v;
    cin >> tamano;
    if (tamano==0)
        return false;
    cin >> k;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int sol = resolver(v,k);

    cout << sol << "\n";
    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/

    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
    /*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}
