// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver( vector<vector<int>> &matriz,int n,int m) {
    if (m==0||n==m) {
        matriz[n][m] = 1;
        return 1;
    }
    else if (m==1||m==n-1) {
        matriz[n][m] = n;
        return n;
    }
    else {
        if (matriz[n-1][m]==-1) {
            matriz[n - 1][m] = resolver(matriz, n - 1, m);
        }
        if (matriz[n - 1][m-1] == -1) {
            matriz[n - 1][m-1] = resolver(matriz, n - 1, m-1);
        }

        return matriz[n][m] = matriz[n - 1][m] + matriz[n - 1][m - 1];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n;
    cin >> m;
    if (!std::cin)
        return false;
    vector<vector<int>> matriz(n+1,vector<int>(m+1,-1));
    int sol = resolver(matriz,n,m);
    cout << sol << "\n";

    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;

    return 0;
}