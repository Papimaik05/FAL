// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void resolver(int supertotal,const vector<pair<int,int>> &matriz,int k,vector<bool> &sol, vector<bool>& solmejor,int costeact,int &superficieactual,int &superfmejor) {
    
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
      resolver(supertotal, matriz, k + 1, sol, solmejor, costeact, superficieactual, superfmejor);
    }
    
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
        info.push_back(pair<int, int>(valor1, valor2));
    }
    
    vector<bool> sol;
    sol.assign(objetos, false);
    vector<bool> solmejor;
    solmejor.assign(objetos, false);
    int costeact = 0;
    int supact = 0;
    int supmejor=0;
    resolver(superficie,info,0,sol,solmejor,costeact,supact,supmejor);

    cout << supmejor << "\n";
    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}