// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
// función que resuelve el problema
void resolver(const vector<int> &v,const int &seguidos,int &inicio,int &suma) {
    int actual = 0;
    bool salida = true;
   
    for (int i = 0; i < seguidos; i++)
    {
        actual += v[i];
    }
    suma = actual;
    for (int i = seguidos; i < v.size(); i++)
    {
        actual += v[i];
        actual -= v[i - seguidos];
        if (actual >= suma) {
            suma = actual;
            inicio = i - seguidos + 1;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int tamano,valor,vagones;
    vector<int> v;
    cin >> tamano;
    cin >> vagones;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int suma = 0;
    int inicio=0;
    resolver(v,vagones,inicio,suma);
    cout << inicio << " " << suma << "\n";
    // escribir sol


}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}