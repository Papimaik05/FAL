// Miguel Mateos Matias
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
 int resolver(const vector<int> &v,long long int &suma) {
     int size = v.size();
     int min = v[0];
     int repetidos = 0;
     int contador = 0;
      suma = 0;


     for (int i = 0; i < size; i++) //coste lineal siendo n el numero de elementos del vector
     {
         if (v[i] == min) {
             repetidos++;
         }
         if (v[i] < min) {
             min = v[i];
             repetidos = 1;
         }
         contador++;
         suma += v[i];
     }
     int aux = repetidos * min;
     contador -= repetidos;
     suma -= aux;
     return contador;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    int valor;
    long long int suma;
    vector<int> v;
    cin >> tamano;
    if (tamano <= 0 || tamano > 1000) {
        cout << "Tamano no admitido,vuelvelo a intentar\n";
        cin >> tamano;
    }
    else {
        for (int i = 0; i < tamano; i++)
        {
            cin >> valor;
            v.push_back(valor);

        }
    }

     int contador=resolver(v,suma);
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}