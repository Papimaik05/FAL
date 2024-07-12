// Miguel Matteos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
long long int nofinal(long long int n) {
    if (n < 10) {
        if (n % 2 == 0) {
            return 0;
        }
        else {
            return n;
        }
    }
    else {
        if (n % 2 == 0) {
            return nofinal(n / 10);
        }
        else {
            return nofinal(n/10)*10 + n%10;
        }
    }

}

long long int final(long long int n, long long int numero, long long int potencia) {
    if (n < 10) {
        if (n % 2 == 0) {
            return numero;
        }
        else {
            return n*potencia + numero;
        }
    }
    else {
        if (n % 2 == 0) {
            return final(n / 10,numero,potencia);
        }
        else {
            return final(n / 10, (n % 10) * potencia + numero, potencia * 10);
        }
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int numero;
    cin >> numero;
    if (!std::cin)
        return false;

    long long int sol1 = nofinal(numero);
    long long int sol2 = final(numero,0,1);

    cout << sol1 << " "<<sol2<< "\n";

    // escribir sol


    return true;

}

int main() {



    while (resuelveCaso())
        ;




    return 0;
}