// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> &v,const int &entrada,int &veces) {
    int actual=1;
    vector<int>  sol;
    for (int i = 1; i < v.size(); i++)
    {
        if (abs(v[i]-v[i-1])<=1) { //hago valor absoluto de la resta,tiene que ser menor o igual que 1
            actual++;
            if (actual == entrada) { //si ya he alcanzado la superficie adecuada
                veces++;
                sol.push_back(i - actual+1); //aniado el inicio de la superficie
            }
        }
        else { 
            actual = 1; 
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor,cigual;
    vector<int> v;
    cin >> tamano;
    cin >> cigual;
    
    if (tamano==0 && cigual==0)
        return false;

    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    int veces = 0;
    vector<int> sol = resolver(v,cigual,veces);

    cout << veces << " ";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";

    

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/

    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
    /*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}
