// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(const vector<int> &v,int &maximo,int &veces,int &desde) {
    int actual = 0;
    int ult = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0) {
            actual++;
            if (actual >= maximo) {
                maximo = actual;
                ult = i;
            }
        }
        else {
            actual = 0;
        }
    }
    actual = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0) {
            actual++;
            if (actual == maximo) {
                veces++;
            }
        }
        else {
            actual = 0;
        }
    }

    if (ult == 0 && v[0]<=0) {
        desde = v.size();
    }
    else {
        desde = v.size() - 1 - ult;
    }
    
      
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
    int maximo=0, veces=0, desde=0;
    resolver(v,maximo,veces,desde);

    // escribir sol
    cout << maximo << " " << veces << " " << desde<<"\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

    while (resuelveCaso())
        ;

    return 0;
}