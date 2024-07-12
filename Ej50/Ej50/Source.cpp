// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
typedef struct {
    bool presentado;
    int numpartidos;
    int ronda;
}tSol;

tSol resolver(const vector<string> &v,int ini,int fin,int rondas) {
    if (ini+1==fin) {
        if (v[ini] != "NP") {
            return { true,0,0 };
        }
        else {
            return { false,0,0 };
        }
    }
    else {
        int mitad = (ini+fin) / 2;
        tSol Izda = resolver(v, ini, mitad, rondas);
        tSol Drcha = resolver(v, mitad,fin, rondas);

        if (Izda.ronda < rondas && Drcha.ronda<rondas) {
            if (Izda.presentado && Drcha.presentado) {
                return { true,Izda.numpartidos+ Drcha.numpartidos + 1,Izda.ronda+1 };
            }
            else if (Izda.presentado || Drcha.presentado) {
                if (Izda.presentado) {
                    return { true,Izda.numpartidos+Drcha.numpartidos,Izda.ronda + 1 };
                }
                else {
                    return { true,Drcha.numpartidos+ Izda.numpartidos,Drcha.ronda + 1 };
                }
            }
            else {
                return { false,Izda.numpartidos+Drcha.numpartidos,Izda.ronda+1 };
            }
        }
        else {
            return {true,Izda.numpartidos+ Drcha.numpartidos,Izda.ronda};
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, rondas;
    cin >> tamano;
    cin >> rondas;
    if (!std::cin)
        return false;
    string valor;
    vector<string> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    tSol sol = resolver(v,0,v.size(),rondas);

    cout << sol.numpartidos << "\n";

    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}