// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
typedef struct {
    bool sol;
    int suma;
}tSolucion;
// función que resuelve el problema
tSolucion resolver(const  vector<int> &v,int ini,int fin) {
    if (ini + 1 == fin) {
        return {true,v[ini]};
    }
    else {
        int mitad = (ini + fin) / 2;
        tSolucion Izda = resolver(v, ini, mitad);
        tSolucion Drcha = resolver(v, mitad, fin);

        if (Izda.sol && Drcha.sol &&Izda.suma < Drcha.suma) {
            return {true,Izda.suma+Drcha.suma};
        }
        else {
            return { false,0 };
        }
    } 
    


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int fila,columna,valor;
    cin >> fila;
    cin >> columna;
    if (!std::cin)
        return false;
    vector<vector<int>> v (fila,vector<int>(columna) );
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++) {
            cin >> valor;
            v[i][j] = valor;
        }
    }
    int i = 0;
    tSolucion fin ;
    fin = resolver(v[0], 0, columna);
    i++;
    while (i < fila  && fin.sol == true) {
        fin = resolver(v[i],0,columna);
        i++;
    }
    if (fin.sol==true){
        cout << "SI \n";
    }
    else {
        cout << "NO \n";
    }

    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}