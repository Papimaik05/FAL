// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
    vector<char> sol;
    vector<bool> b;
}tSol;
// función que resuelve el problema
void escribir(const vector<char>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}
void resolver(int n,int m,int k,tSol &sol) {
    for (char i = 'a'; i < 'a'+ n; i++)
    {
        sol.sol[k] = i;
        if (!sol.b[i - 'a']) {
            sol.b[i - 'a'] = true;
            if (k == m - 1) {
                escribir(sol.sol);
                cout << "\n";
            }
            else {
                resolver(n, m, k+1, sol);
            }
            sol.b[i - 'a'] = false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int letras, tamano;
    cin >> letras;
    cin >> tamano;
    if (!std::cin)
        return false;
    
    tSol s;
    s.sol.resize(tamano);
    s.b.assign(letras,false);
    resolver(letras,tamano,0,s);
    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}