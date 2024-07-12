// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
// función que resuelve el problema
void resolver(vector <int> &v) {
    sort(v.begin(), v.end());
    int buenos = 0;
    int i = 1;

    while (i < v.size()) { //coste  n(siendo n el tamano del vector)
        if (v[i] == v[buenos]) { //comparo si ya lo tengo repetido,si no es el caso lo cambio en la posicion buenos;
            i++;
        }
        else {
            buenos++;
            swap(v[i], v[buenos]);
            i++;
           
        }
    }
    
    v.resize(buenos+1); //ajusto el tamano a buenos
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    int valor;
    vector<int> v;
    cin >> tamano;
    if (!std::cin)
        return false;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    resolver(v);

    for (int i = 0; i < v.size(); i++) 
    {
        cout << v[i] << " ";
    }
    cout << "\n";
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
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}