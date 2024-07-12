// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;


// función que resuelve el problema
vector<int> resolver(vector<int> v,int anio) {
    
    int maximo=v[0];
    anio++;
    vector<int> superaron;

    for (int i = 1; i < v.size(); i++)
    {
        if(v[i] > maximo) {
            superaron.push_back(anio);
            maximo = v[i];
        }
        anio++;
    }
    
    return superaron;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   
    int anio1, anio2;
    long int valor;
    vector<int> v;
    cin >> anio1;
    cin >> anio2;

    for (int i = anio1; i <= anio2; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    vector<int> sol = resolver(v,anio1);

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
    // escribir sol


}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}