// Miguel Mateos Matias
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
/*EXPLICACION:
 Para realizar este problema ,compruebo si alguno de los vectores esta vacio para poder devolver el otro,
 si los dos están llenos ,procedo a realizar el algoritmo,que se basa en un bucle while hasta que la i y la j que son dos auxiliares(que nos indican en que posicion de los vectores estamos)  sean iguales que el tamaño
 de sus correspondientes vectores,vamos comparando con los 3 distintos casos,en caso de que los elementos del vector(v1[i]==v2[j]) sean iguales  se aumentan la i y la j debido a que no cumplen la propiedad necesaria de la
 disyuncion,si un elemento es menor que otro se añade ese elemento y se suma su respectiva i/j

*/
void resolver(const vector<int> &v1 , const vector<int> &v2,vector<int> &sol) {
    int i = 0;
    int j = 0;
    if (v1.size() == 0 && v2.size()!=0) {
        sol = v2;
    }
    else if (v2.size() == 0) {
        sol = v1;
    }
    else {
        while (i < v1.size() && j < v2.size()) {

            if (v1[i] < v2[j]) {
                sol.push_back(v1[i]);
                i++;
            }
            else if (v2[j] < v1[i]) {
                sol.push_back(v2[j]);
                j++;
            }
            else if (v1[i] == v2[j]) {
                i++;
                j++;
            }
        }
        while (i < v1.size()) {
            sol.push_back(v1[i]);
            i++;
        }
        while (j < v2.size()) {
            sol.push_back(v2[j]);
            j++;
        }
    }
   
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v1;
    vector<int> v2;
    vector<int> sol;
    int valor;
    cin >> valor;
    while (valor != 0) {
        v1.push_back(valor);
        cin >> valor;
    }
    cin >> valor;
    while (valor != 0) {
       
        v2.push_back(valor);
        cin >> valor;
    }


    resolver(v1,v2,sol);

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
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

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}