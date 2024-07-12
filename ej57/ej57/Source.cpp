// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void escribirvector(vector<char>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }

}
void resolver(int n,int m,int k,vector<char> &v) {

    for (char i = 'a'; i < 'a'+n; i++)
    {
        v[k] = i;
        if(k==m-1){
            escribirvector(v);
            cout << "\n";
        }
        else {
            resolver(n,m,k+1,v);
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
    vector<char> sol(tamano);
    resolver(letras, tamano, 0, sol);


    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;

    return 0;
}