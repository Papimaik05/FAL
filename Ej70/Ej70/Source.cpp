// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class comparador {
public:
    bool operator ()(pair <int, int > p1,pair <int, int > p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

int estimar(const int& supertotal, const vector<pair<int,int>>& matriz, int costeact, int  k) {
    int i = k + 1;
    int sCoste = costeact;
    int sSuper = 0;
    while (i < matriz.size() && sCoste + matriz[i].first <= supertotal) { // Cn la siguiente que pasaria
        sCoste += matriz[i].first;
        sSuper += matriz[i].second;
        i++;
    }
    if (i < matriz.size() && sCoste < supertotal) { //cuando no has podido meter la siguiente pieza
        sSuper += matriz[i].second * (supertotal - sCoste) / matriz[i].first + 1; //
    }
    
    return sSuper;
}
// función que resuelve el problema
void resolver(int supertotal, const vector<pair<int,int>> & matriz, int k, vector<bool>& sol, vector<bool>& solmejor, int costeact, int& superficieactual, int& superfmejor) {

    sol[k] = true;
    costeact += matriz[k].first;
    superficieactual += matriz[k].second;
    if (costeact <= supertotal) {
        if (k == sol.size() - 1) {
            if (superficieactual > superfmejor) {
                solmejor = sol;
                superfmejor = superficieactual;
            }
        }
        else {
            resolver(supertotal, matriz, k + 1, sol, solmejor, costeact, superficieactual, superfmejor);
        }
    }
    costeact -= matriz[k].first;
    superficieactual -= matriz[k].second;
    sol[k] = false;
    if (k == sol.size() - 1) {
        if (superficieactual > superfmejor) {
            solmejor = sol;
            superfmejor = superficieactual;
        }
    }
    else {
        if (estimar(supertotal, matriz, costeact, k) + superficieactual >= superfmejor) {
            resolver(supertotal, matriz, k + 1, sol, solmejor, costeact, superficieactual, superfmejor);
        }
    }
}
int inicializar(const int& supertotal, const vector<pair<int, int>>& matriz) {
    int i = 0;
    int sCoste = 0;
    int sSuper = 0;
    while (i < matriz.size() && sCoste + matriz[i].first <= supertotal) { // Cn la siguiente que pasaria
        sCoste += matriz[i].first;
        sSuper += matriz[i].second;
        i++;
    }
    return sSuper;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int objetos, superficie;

    cin >> objetos >> superficie;
    if (!std::cin)
        return false;

    vector<pair<int, int>> info;
    int valor1;
    int valor2;
    for (int i = 0; i < objetos; i++)
    {
        cin >> valor1;
        cin >> valor2;
        info.push_back({valor1,valor2});
    }
    sort(info.begin(), info.end(), comparador());
    vector<bool> sol(objetos);
    //sol.assign(objetos, false);
    vector<bool> solmejor;
    int costeact = 0;
    int supact = 0;
    int supmejor = inicializar(superficie,info);
    resolver(superficie, info, 0, sol, solmejor, costeact, supact, supmejor);

    cout << supmejor << "\n";
    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}