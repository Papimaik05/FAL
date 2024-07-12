// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int mincarga(const vector<int>& v, const int& ini, const int& fin) {
    int aux = v[ini];
    for (int i = ini; i < fin; i++)
    {
        if ((v[i])>aux) {
            aux = v[i];
        }
    }
    return aux;
}
int cargatotal(const vector<int>& v, const int& ini, const int& fin) {
    int suma = 0;
    for (int i = ini; i < fin; i++)
    {
        suma += v[i];
    }
    return suma;
}
int contarDias(const vector<int>& v, const int &peso) {
    int dias = 1;
    int suma = 0;
    int i = 0;
    while (i < v.size()) {
        if (suma + v[i] <= peso) {
            suma += v[i];
        }
        else {
            dias++;
            suma = v[i];
        }
        i++;
    }
    return dias;
}
int resolver(const vector<int> &v,const int &numviajes,int ini,int fin) {
    if (ini == fin) {
        return ini;
    }
    else {
        int mitad = (ini + fin) / 2;
        int aux = contarDias(v, mitad);
        if (aux <= numviajes) {
            return resolver(v, numviajes, ini, mitad);
        }
        else {
            return resolver(v, numviajes, mitad+1, fin);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int tamano,viajes,valor;
    cin >> tamano;
    cin >> viajes;
    if (tamano==0 && viajes==0)
        return false;

    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int aux = mincarga(v, 0, v.size());
    int aux2 = cargatotal(v, 0, v.size());

    int sol = resolver(v,viajes,aux,aux2);

    cout << sol << "\n";
    // escribir sol

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}
