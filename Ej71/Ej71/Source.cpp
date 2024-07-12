// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(const vector<pair<int, int>> &info,const int &tida,const int &tvuelta,int k,vector<bool> &sol,vector<bool> &solmejor,int &satactu,int &satopt,int &ti,int &tv) {
    sol[k] = true;
    satactu += info[k].second;
    ti += info[k].first;
    
    if (ti<=tida+tvuelta) {
        if (k == sol.size() - 1) {
            if (satactu >= satopt) {
                satopt = satactu;
            }
        }
        else {
            resolver(info, tida, tvuelta, k + 1, sol, solmejor, satactu, satopt, ti, tv);
        }
    }
    satactu -= info[k].second;
    ti -= info[k].first;
    sol[k] = false;
    if (k == sol.size() - 1) {
        if (satactu >= satopt) {
            satopt = satactu;
        }
    }
    else {
        resolver(info, tida, tvuelta, k + 1, sol, solmejor, satactu, satopt, ti, tv);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int ncanciones, tida, tvuelta;
    cin >> ncanciones >> tida >> tvuelta;
    if (ncanciones==0 && tida==0 &&tvuelta==0)
        return false;

    vector<pair<int, int>> info;
    int valor1, valor2;
    for (int i = 0; i < ncanciones; i++)
    {
        cin >> valor1;
        cin >> valor2;
        info.push_back({ valor1,valor2 });
    }
    vector<bool> sol;
    sol.assign(ncanciones, false);
    vector<bool> solmejor;
    int satactual = 0;
    int satopt = 0;
    int ti = 0;
    int tv = 0;
    resolver(info,tida,tvuelta,0,sol,solmejor,satactual,satopt,ti,tv);
    if (satopt == 0) {
        cout << "Imposible \n";
    }
    else {
        cout << satopt << "\n";
    }

    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}
