// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(int ramas,int altura,int k,const vector<vector<int>> &calaux,vector<int> &sol,int &satisactual,vector<bool> &marca,int &satismejor,const vector<int> &acum) {
    
    for (int i = 0; i < ramas ; i++)
    {
        sol[k] = i;
        satisactual += calaux[k][i];
        if (!marca[i]) {
            marca[i] = true;
            if (k==altura-1) {
                if (satisactual > satismejor) {
                    satismejor = satisactual;
                }
            }
            else {
                if (satisactual + acum[k + 1] > satismejor) {
                    resolver(ramas, altura, k + 1, calaux, sol, satisactual, marca, satismejor,acum);
                }
            }
            marca[i] = false;
            
        }
        satisactual -= calaux[k][i];
    }


    return satismejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, ninos;
    cin >> tamano >> ninos;
    if (!std::cin)
        return false;
    int valor;
    vector<vector<int>> calaux(ninos, vector<int>(tamano));
    for (int i = 0; i < ninos; i++)
    {
        for (int j = 0;j < tamano;j++) {
            cin >> valor;
            calaux[i][j] = valor;
        }
    }

    vector<int> acummax(ninos);
    for (int i = 0; i < ninos; i++)
    {
        int aux = calaux[i][0];
        for (int j = 0;j < tamano;j++) {
            if (calaux[i][j] > aux) {
                aux = calaux[i][j];
            }
        }
        acummax[i] = aux;
    }
    for (int i = acummax.size()-1; i > 0; i--)
    {
        acummax[i - 1] += acummax[i];
    }

    vector<int> sol(ninos);
    int satisactual = 0;
    vector<bool> marca;
    marca.assign(tamano, false);
    int satismejor = 0;
    int solfinal = resolver(tamano,ninos,0,calaux,sol,satisactual,marca,satismejor,acummax);

    cout << solfinal << "\n";
    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;
    return 0;
}