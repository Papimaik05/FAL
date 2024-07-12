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
int resolver(int ramas,int altura,int k,const vector<vector<int>> &matriz,vector<int> &sol,vector<bool> &marcas,int &satisact,int &satisopt) {

    for (int i = 0; i < ramas; i++)
    {
        sol[k] = i;
        satisact += matriz[k][i];
        if (!marcas[i]) {
            marcas[i] = true;
            if (k == altura - 1) {
                if (satisact < satisopt) {
                    satisopt = satisact;
                }
            }
            else {
                
                    satisopt = resolver(ramas, altura, k + 1, matriz, sol, marcas, satisact, satisopt);
               
            }
            marcas[i] = false;
        }
        satisact -= matriz[k][i];
    }
    return satisopt;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numtrabajos;
    cin >> numtrabajos;
    if (numtrabajos==0)
        return false;
    int valor;
    vector<vector<int>> matriz (numtrabajos, vector<int>(numtrabajos));
    for (int i = 0; i < numtrabajos; i++)
    {
        for (int j = 0; j < numtrabajos; j++)
        {
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
    vector<int> maximos;
    for (int i = 0; i < numtrabajos; i++)
    {
        int max = 0;
        for (int j = 0; j < numtrabajos; j++)
        {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
        maximos.push_back(max);
    }
    for (int i = maximos.size()-1; i > 0; i--)
    {
        maximos[i - 1] += maximos[i];
    }
    vector<int> sol(numtrabajos);
    vector<bool> marca;
    marca.assign(numtrabajos, false);
    int satisactual = 0;
    int satisoptima = maximos[0];
    int solfinal = resolver(numtrabajos,numtrabajos,0,matriz,sol,marca,satisactual,satisoptima);
    cout << solfinal << "\n";
    
    // escribir sol

    return true;

}

int main() {


    while (resuelveCaso())
        ;

    return 0;
}
