// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
void resolver(int ramas,int altura,int k,const vector<vector<int>> &trajemat, const vector<vector<int>>& zapatmat, vector<bool> &trajeusado, vector<bool> &zapatousado,vector<int>sol,int &satisactual,int&satisoptima) {
    for (int i = 0; i < ramas; i++)
    {
        sol[k] = i;
        if (!trajeusado[i]) {
            trajeusado[i] = true;
            if (k == altura - 1) {
                if (satisactual > satisoptima) {
                    satisoptima = satisactual;
                }
                else {
                    resolver(ramas, altura, k + 1, trajemat, zapatmat, trajeusado, zapatousado, sol, satisactual, satisoptima);
                }
            }
            trajeusado[i] = false;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int modelos;
    cin >> modelos;

    vector<vector<int>> trajemat(modelos, vector<int>(modelos));
    vector<vector<int>> zapatmat(modelos, vector<int>(modelos));

    int valor;
    for (int i = 0; i < modelos; i++)
    {
        for (int j = 0; j < modelos; j++)
        {
            cin >> valor;
            trajemat[i][j] = valor;
        }
    }
    for (int i = 0; i < modelos; i++)
    {
        for (int j = 0; j < modelos; j++)
        {
            cin >> valor;
            zapatmat[i][j] = valor;
        }
    }
    vector<bool> trajeusado;
    vector<bool> zapatousado;
    trajeusado.assign(modelos,false);
    trajeusado.assign(modelos, false);
    int satisactual = 0;
    int satisoptima;
    vector<int> sol;
    resolver(modelos,modelos,0,trajemat,zapatmat,trajeusado,zapatousado,sol,satisactual,satisoptima);

    cout << satisoptima << "\n";
    // escribir sol


}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}