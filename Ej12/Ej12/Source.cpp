// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

// Los costes te los pongo debajo,segun vas haciendo el ejercicio

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int tamano,dia;
    long int valor;
    vector<long int>v;
    cin >> tamano;
    if (tamano==-1) //coste cte
        return false;
    for (int i = 0; i < tamano; i++) //coste n(siendo n=tamano)
    {
        cin >> valor;
        v.push_back(valor);
    }
    vector<long int>acum(v.size() + 1);
    acum[0] = 0; //coste cte
    for (int i = 1; i < acum.size(); i++) //coste n-1(siendo n el tamano del vector de acumulados)
    {
        acum[i] = acum[i - 1] + v[i - 1]; //coste cte
    }
    int preguntas;
    cin >> preguntas;
    for (int i = 0; i < preguntas; i++) //coste n(siendo n el numero de preguntas)
    {
        cin >> dia;
        cout << acum[acum.size()-1]-acum[dia-1]    <<"\n";
    }
    cout << "---\n";


    return true;

}

int main() {


    while (resuelveCaso())
        ;




    return 0;
}
