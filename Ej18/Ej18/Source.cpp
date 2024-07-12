//Miguel Mateos
//A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int> &v,int &inicio,int &longitud) {

    int suma = 0;
    int maximasuma = 0;
    int auxLong = 0;
    for (int i = 0; i < v.size(); i++)
    {
        suma += v[i];
        if (suma > 0) {
            auxLong++;
            if (suma > maximasuma) {
                maximasuma = suma;
                inicio = i - auxLong + 1;
                longitud = auxLong;
            }
            else if (suma == maximasuma) {
                if (auxLong < longitud) {
                    inicio = i - auxLong + 1;
                    longitud = auxLong;
                }

            }

        }
        else {
            suma = 0;
            auxLong = 0;
        }
    }

    return maximasuma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    vector<int> v;
    cin >> tamano;
    if (!std::cin)
        return false;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int longitud = 0;
    int inicio=0;
    int sol = resolver(v,inicio,longitud);

    cout << sol << " " << inicio << " " << longitud << "\n";

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    while (resuelveCaso())
        ;
    return 0;
}