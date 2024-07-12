// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void escribir(const vector<int>& sol) {
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
}
bool esValida(int k, const vector<int>& sol, const vector<string>& v, int ramas,const int &s,const vector<int> &snino) {

    if (k % 2 == 1) {
        if (snino[k / 2] < s) {
            return false;
        }
        if (k > 0 && v[sol[k]] <= v[sol[k - 1]]) {
            return false;
        }
    }
    


    return true;
}
void resolver(int ramas, int altura, int k, const vector<string>& v, vector<int>& sol, bool& hay,const vector <vector<int>> &calaux,vector<int> &acumulados,const vector<int> &unidades,const int &satis,vector<int> &snino) {

    for (int i = 0; i < ramas; i++)
    {
        if (acumulados[i] < unidades[i]) {
            sol[k] = i;
            acumulados[i]++;
            snino[k / 2] += calaux[k / 2][i];
            if (esValida(k, sol, v, altura,satis,snino)) {
                if (k == altura - 1) {
                    escribir(sol);
                    cout << "\n";
                    hay = true;
                }
                else {
                    resolver(ramas, altura, k + 1, v, sol, hay, calaux, acumulados,unidades,satis,snino);
                }
            }
            acumulados[i]--;
            snino[k / 2] -= calaux[k / 2][i];
        }
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, ninos,satisf;
    cin >> tamano >> ninos >>satisf;
    if (!std::cin)
        return false;
    vector<int> unidades;
    int valor;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        unidades.push_back(valor);
    }
    vector<string> v;
    string aux;
    for (int i = 0; i < tamano; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }
    vector <vector<int>> calaux (ninos,vector<int> (tamano));
    for (int i = 0; i < ninos; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            cin >> valor;
            calaux[i][j] = valor;
        }
    }
    vector<int>sol(2 * ninos);
    bool hay = false;
    vector<int> acumulados;
    acumulados.assign(tamano, 0);
    vector<int> snino;
    snino.assign(ninos,0);
    resolver(v.size(), 2 * ninos, 0, v, sol, hay,calaux,acumulados,unidades,satisf,snino);

    if (hay == false) {
        cout << "SIN SOLUCION \n";
    }
    // escribir sol


    return true;

}

int main() {



    while (resuelveCaso())
        ;


    return 0;
}