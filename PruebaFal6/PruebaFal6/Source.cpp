// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
/*Funcion recursiva*/
/* función que resuelve el problema
* buscarIzda(vector,int ,int) : {ini         para     ini==fin ||ini+1 ==fin
*                               {buscarIzda(v,mitad + 1, fin)  para v[mitad]!=true
*                               { buscarIzda(v,ini, mitad+1   para  v[mitad]==true
* 
* //Recurrencia
* 
* T(n) =={  c1    n==1
*        { T(n/2) + c2    n>1
*        
* Siendo n el numero de elementos del vector que viene dado por fin - ini
* 
* DESPLIEGUE 
* 
* T(n) = T(n/2) + c1 = T(n/4)+c1+c1 =T(n/8) + c1 + c1 +c1 ...  = T(n/2^k) + kc1 ... = T(1)+log(n)*c1   COSTE(log n)
*/
int buscarIzda(const vector<bool> &v,int ini,int fin) {
    if (ini == fin) { //vacio  coste cte
        return ini;
    }
    else if (ini + 1 == fin) { //1 solo elemento   coste cte
        return ini;
    }
    else {   //coste log n
        int mitad = (ini + fin - 1) / 2;
        if (!v[mitad]) {
            return buscarIzda(v,mitad + 1, fin);
        }
        else {
            return buscarIzda(v,ini, mitad+1);
        }
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int tamano;
    cin >> tamano;
    if (!cin)
        return false;
    vector<bool> v;
    int valor;
    for (long long int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    long long int sol1 = buscarIzda(v,0,v.size());
    if (v[sol1] ) {
        cout << v.size() - sol1 << "\n";
    }
    else {
        cout << 0<< "\n";
    }

    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;
    return 0;
}
