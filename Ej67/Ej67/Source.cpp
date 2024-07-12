// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
//El arbol de exploracion tiene como ramas los trabajos y cada etapa corresponde a un funcionario
// En cada etapa se asigna un trabajo a un funcionario.El vector solucion tiene tamaño el numero de funcionarios y cada componente guarda la tarea asignada a ese funcionario
// función que resuelve el problema
void resolver(int ramas, int altura, int k, const vector<vector<int>>& matriz, vector<int>& sol, vector<bool>& marcas, int& satisact, int& satisopt, const vector<int>& acum) {

    for (int i = 0; i < ramas; i++)
    {
        sol[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            satisact += matriz[k][i];
            if (k == altura - 1) {
                if (satisact < satisopt) {
                    satisopt = satisact;
                }
            }
            else {
                if (satisact+acum[k+1]  < satisopt) {
                   resolver(ramas, altura, k + 1, matriz, sol, marcas, satisact, satisopt, acum);
                }
            }
            marcas[i] = false;
            satisact -= matriz[k][i];
        }
        
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numtrabajos;
    cin >> numtrabajos;
    if (numtrabajos == 0)
        return false;
    int valor;
    vector<vector<int>> matriz(numtrabajos, vector<int>(numtrabajos));
    for (int i = 0; i < numtrabajos; i++)
    {
        for (int j = 0; j < numtrabajos; j++)
        {
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
    vector<int> minimos;
    for (int i = 0; i < numtrabajos; i++)
    {
        int min = 20*10000;
        for (int j = 0; j < numtrabajos; j++)
        {
            if (matriz[i][j] < min) {
                min = matriz[i][j];
            }
        }
        minimos.push_back(min);
    }
    for (int i = minimos.size() - 1; i > 0; i--)
    {
        minimos[i - 1] += minimos[i];
    }

    vector<int> sol(numtrabajos);
    vector<bool> marca;
    marca.assign(numtrabajos, false);
    int satisactual = 0;
    int satisoptima = 20*10000;
    resolver(numtrabajos, numtrabajos, 0, matriz, sol, marca, satisactual, satisoptima, minimos);
    cout << satisoptima << "\n";

    // escribir sol

    return true;

}

int main() {


    while (resuelveCaso())
        ;

    return 0;
}
