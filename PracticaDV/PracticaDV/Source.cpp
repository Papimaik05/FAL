// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
    bool sol;
    int numpares;
}tSolucion;
// función que resuelve el problema

//Definicion recursiva
/*
* 
* 
    Hemos utilizado un struct para contabilizar el numero de pares y si se va cumpliendo la condicion de caucasico.Bajamos hasta el nivel mas bajo(1 elemento)
    y vemos si es par o no,ademas tenemos un Izda y Drcha que nos van a ir contando los pares de ambas mitades,y si se cumple que abs(Drcha.numpares - Izda.numpares)<=2 && Izda.sol && Drcha.sol entonces
    nos devolvera true y el numero de pares totales(Izda +Drcha) , en caso contrario nos devolvera false

   Recurrencia

   T(n) -------{c0              n==1
               {2T(n/2) + c1    n>1
   
   DESPLIEGUE=
   T(n) = 2T(n/2) + c1
        = 2(2T(n/2^2)+c1)+c1
        ...
        =2^k T(n/2^k) +c1(Sum 2 ^k-1)

   El orden es O(n) ==>2^log(n) * T(1) + c1^(2^log(n)  - 1)
*/
tSolucion resolver(const vector<int> &v,int ini,int fin) {
    if (ini + 1 == fin) { //1 elemento
        if (v[ini] % 2 == 0) {
            return { true,1 };
        }
        else {
            return { true,0 };
        }
    } 
    else { // >1 elemento
        int mitad = (ini + fin) / 2;
        tSolucion Izda = resolver(v,ini,mitad);
        tSolucion Drcha = resolver(v, mitad, fin);
        
        if (abs(Drcha.numpares - Izda.numpares)<=2 && Izda.sol && Drcha.sol) {
            return { true,Izda.numpares + Drcha.numpares };
        }
        else {
            return { false,Izda.numpares + Drcha.numpares };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    cin >> tamano;
    if (tamano==0)
        return false;
    vector<int> v;
    for (int i = 0; i < tamano; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }
    tSolucion sol = resolver(v,0,v.size());
    if (sol.sol) {
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
