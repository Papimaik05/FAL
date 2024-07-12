// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
typedef struct tSolucion{
    bool sol;
    long int minimo;
    long int maximo;
};


long int maxi(const vector<long int> &v, const long int &ini, const long int &fin) {
    long int maximo = v[ini];
    long int aux = ini;
    for (long int i = ini; i < fin; i++) {
        if (v[i] > maximo) {
            maximo = v[i];
            aux= i;
        }
    }
        return aux;
}
long int mini(const vector<long int>& v, const long int& ini, const long int& fin) {
    long  int aux = ini;
    long  int minimo = v[ini];
    for (long  int i = ini; i < fin; i++) {
        if (v[i] < minimo) {
            minimo = v[i];
            aux = i;
        }
    }
    return aux;
}
tSolucion resolver(const vector< long int> &v,  long int ini, long  int fin ) {

    if (ini + 1 == fin) {
        return { false,ini,ini };
    }
    else if (ini + 2 == fin) {
        return { false,mini(v,ini,fin),maxi(v,ini,fin) };
    }
    else {
        long  int posmax = maxi(v,ini,fin);

        if (posmax == ini) {
            auto aux1 = resolver(v, ini + 1, fin);
            return {aux1.sol,aux1.minimo,posmax};
        }
        else if (posmax==fin-1) {
            auto aux2= resolver(v,ini,fin-1);
            return { aux2.sol,aux2.minimo,posmax };
        }
        else {
            tSolucion Izda = resolver(v,ini,posmax);

            tSolucion Drcha = resolver(v, posmax+1, fin);
            int aux;
            if (min(v[Izda.minimo], v[Drcha.minimo]) == v[Izda.minimo]) {
                aux = Izda.minimo;
            }
            else {
                aux = Drcha.minimo;
            }

            return {v[Izda.minimo] < v[Drcha.maximo] || Izda.sol || Drcha.sol,aux,posmax };
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long  int tamano;
    long  int valor;
    cin >> tamano;
    if (!std::cin)
        return false;
    vector< long int> v;
    for ( long int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    tSolucion sol = resolver(v,0,v.size());

    if (sol.sol) {
        cout << "ELEGIR OTRA \n";
    }
    else {
        cout << "SIEMPRE PREMIO \n";
    }

    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}