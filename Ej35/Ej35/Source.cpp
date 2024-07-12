// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
long long int nofinal(long long int n,int maximo) {
    if (n < 10) {
        if (n >= maximo) {
            return n;
        }
        else {
            return 0;
        }
    }
    else {
        if ((n%10) >= maximo) {
            return nofinal(n/10,n%10)*10 + n%10;
        }
        else {
            return nofinal(n / 10, maximo);
        }
    }

}

long long int final(long long int n, int maximo,long long int total,int potencia) {
    if (n < 10) {
        if (n >= maximo) {
            return n*potencia + total;
        }
        else {
            return total;
        }
    }
    else {
        if ((n % 10) >= maximo) {
            return final(n/10,n%10,(n%10)*potencia + total,potencia*10);
        }
        else {
            return final(n/10,maximo,total,potencia);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int numero;
    cin >> numero;

    long long int sol1 = nofinal(numero,0);
    long long int sol2 = final(numero, 0, 0, 1);
        // escribir sol
    cout << sol1 <<"  "<<sol2<< "\n";

}

int main() {


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    return 0;
}