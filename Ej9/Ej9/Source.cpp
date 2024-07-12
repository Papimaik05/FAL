// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void acumulado(const vector <int> &v,vector<long long int> &acumulados) {
    acumulados[0] = 0;
    for (int i = 1; i < acumulados.size(); i++)
    {
        acumulados[i] = acumulados[i - 1] + v[i - 1];
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int inicio;
    int final;
    int valor;
    vector <int> v;
    cin >> inicio;
    cin >> final;
    if (inicio==0 && final==0)
        return false;

    for (int i = inicio; i <= final; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    vector <long long int> acumulados(v.size()+1);

    acumulado(v, acumulados);

    int preguntas;
    cin >> preguntas;
    for (int i = 0; i < preguntas; i++)
    {
        int preg1, preg2;
        cin >> preg1;
        cin >> preg2;

        cout << acumulados[preg2 - inicio + 1] - acumulados[preg1 - inicio] << "\n";
    }
    cout << "---\n";
    return true;

    // escribir sol


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
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}
