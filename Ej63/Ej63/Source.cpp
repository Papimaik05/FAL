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
bool esValida(int k, const vector<int>& sol,const vector<string>& v,int ramas) {
    
    if (k % 2 == 1) {
        if (k > 0 && sol[k-1]>=sol[k]) {
            return false;
        }
        if (k>0 && v[sol[k-1]]==v[sol[k]]) {
            return false;
        }
    }
   
    return true;
}
void resolver(int ramas,int altura,int k, const vector<string> &v,vector<int> &sol,bool &hay) {

    for (int i = 0; i < ramas; i++)
    {
        sol[k] = i;

        if (esValida(k,sol,v,altura)) {
            if (k == altura - 1) {
                escribir(sol);
                cout << "\n";
                hay = true;
            }
            else {
                resolver(ramas, altura, k + 1, v, sol, hay);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano, ninos;
    cin >> tamano >> ninos;
    if (!std::cin)
        return false;
    vector<string> v;
    string aux;
    for (int i = 0; i < tamano; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }
    vector<int>sol(2 * ninos);
    bool hay = false;
    resolver(v.size(),2*ninos,0,v,sol,hay);

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