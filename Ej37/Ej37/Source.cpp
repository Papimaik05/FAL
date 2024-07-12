//Miguel Mateos
//A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int buscarIzda(vector<int> v,int buscado,int inicio,int final) {
    if (inicio == final) { //vacio
        return inicio;
    }
    else if (inicio + 1 == final) { //1 elemento
        return inicio;
    }
    else {
        int mitad = (inicio + final - 1 ) / 2;
        if ( buscado > v[mitad]) {
            return buscarIzda(v,buscado,mitad+1,final);
        }
        else{
            return buscarIzda(v, buscado, inicio, mitad + 1);
        }
    }
}
int buscarDrcha(vector<int> v,int buscado,int inicio,int final) {
    if (inicio == final) { //vacio
        return inicio;
    }
    else if (inicio + 1 == final) {
        return inicio;
    }
    else {
        int mitad = (inicio + final) / 2;
        if ( buscado < v[mitad]) {
            return buscarDrcha(v, buscado, inicio, mitad);
        }
        else {
            return buscarDrcha(v,buscado,mitad,final);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    int buscar,valor;
    vector<int> v;
    cin >> tamano;
    cin >> buscar;
    if (!std::cin)
        return false;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int sol1 = buscarIzda(v,buscar,0,v.size());

    if (sol1 == v.size() || v[sol1]!=buscar ) {
        cout << "NO EXISTE \n";
    }
    else {
        int sol2 = buscarDrcha(v, buscar, 0, v.size());

        if (sol1 == sol2) {
            cout << sol1 << "\n";
        }
        else {
            cout << sol1 << " " << sol2 << "\n";
        }
    }

    


    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.

    while (resuelveCaso())
        ;

    return 0;
}