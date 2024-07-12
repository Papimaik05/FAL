// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
bool esValida(int k,int i,const vector<int> &sol, const vector<int> &marcas, const vector<int>& v1, const vector<int>& v2) {
    if (k > 0 && sol[k - 1] == sol[k]) { //2 dias seguidos
        return false;
    }
    else if (marcas[i]> k/3+2) { //un tercio y marcas i cuenta el numero de dias
        return false;
    }
    else if (v2[i]<v1[k]) { //el abrigo soporta la cantidad
        return false;
    }
    return true;
}
// función que resuelve el problema
int resolver(const vector<int> &v1, const vector<int>& v2,vector<int> &sol, vector<int>& marcas,int k) {
    int soluciones = 0;
    for (int i = 0; i < v2.size(); i++)
    {
        sol[k] = i;
        marcas[i]++;
        if (esValida(k,i,sol,marcas,v1,v2)) {
            if (k == v1.size() - 1) {
                if (sol[0] != sol[k]) {
                    soluciones++;
                }

            }
            else {
                soluciones += resolver(v1, v2, sol, marcas, k + 1);
            }
        }
        marcas[i]--;
    }
    return soluciones;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int dias,abrigos;
    cin >> dias;
    cin >> abrigos;

    if (dias==0 && abrigos==0)
        return false;
    int precipitacion;
    vector<int> diasv;
    vector<int> abrigosv;
    for (int i = 0; i < dias; i++)
    {
        cin >> precipitacion;
        diasv.push_back(precipitacion);
    }
    for (int i = 0; i < abrigos; i++)
    {
        cin >> precipitacion;
        abrigosv.push_back(precipitacion);
    }
    vector<int> solv(dias);
    vector<int> marcas(abrigos);
    int sol = resolver(diasv,abrigosv,solv,marcas,0);

    if (sol == 0) {
        cout << "Lo puedes comprar \n";
    }
    else {
        cout << sol << "\n";
    }
    // escribir sol

    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}
