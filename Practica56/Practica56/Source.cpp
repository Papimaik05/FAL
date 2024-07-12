// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema

int mintiempo(const vector<int>& v) {
    int aux = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i]) > aux) {
            aux = v[i];
        }
    }
    return aux;
}
int tiempototal(const vector<int>& v) {
    int suma = 0;
    for (int i = 0; i < v.size(); i++)
    {
        suma += v[i];
    }
    return suma;
}
int contarparadas(const vector<int>& v, const int &tiempo) {
    int suma = 0;
    int cont = 0;
    int i = 0;
    while (i < v.size()) {
        if (suma + v[i] <= tiempo) {
            suma += v[i];
        }
        else {
            suma = v[i];
            cont++;
        }
        i++;
    }
    return cont;
}
int resolver(const vector<int> &v,int ini,int fin,int paradas) {
    if (ini == fin) {
        return ini;
    }
    else {
        int mitad = (ini + fin) / 2;
        int aux = contarparadas(v,mitad);
        if (aux <= paradas) {
            return resolver(v,ini,mitad,paradas);
        }
        else {
            return resolver(v,mitad+1,fin,paradas);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, paradas,valor;
    cin >> tamano;
    cin >> paradas;
    if (tamano==0 && paradas==0)
        return false;
    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int aux = mintiempo(v);
    int aux2 = tiempototal(v);

    int sol = resolver(v,aux,aux2,paradas);

    cout << sol << "\n";
    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}
