// Nombre del alumno .....
// Usuario del Juez ......

//HE PILLADO MAL EL ENUNCIADO
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;


// función que resuelve el problema
bool resolver(vector<int> v,int pos) {
    bool bien=true;
    int size = v.size();

    if (pos== size-1) {
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (pos == 0) {

            if ((pos + 1 + i) >= size) {
                return bien;
            }
            if (v[pos] < (v[pos + 1 + i])) {
                bien = true;
            }
            else {
                bien = false;
            }
        }
        else {
            if ((i <= pos) && (pos + 1 + i == size)) {
                return false;
            }
            if ((pos + 1 + i) > size || i == pos ) {
                return bien;
            }
            
            if (v[i] < (v[pos + 1 + i])) {
                bien = true;
            }
            else {
                bien = false;
            }
        }
   
    }
    return bien;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    vector<int> v;
    int tamanoarray;
    int posicion;
    cin >> tamanoarray;
    if (tamanoarray < 1 || tamanoarray > 300000) {
        return false;
    }

    cin >> posicion;
    if (posicion < 0 || posicion  > (tamanoarray -1)) {
        return false;
    }

    for (int i = 0; i < tamanoarray; i++)
    {
        int numero;
        cin >> numero;
        v.push_back(numero);
    }
    bool sol = resolver(v,posicion);

    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    // escribir sol

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}