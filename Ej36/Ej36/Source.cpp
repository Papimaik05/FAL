// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool nofinal(long long int n,long long int sumaatras,long long int sumadelante) {
    if (n % 10 == 0) {
        return false;
    }
    else {
        sumadelante -= (n % 10);
        if (n < 10 ) {
            if ((sumaatras % n) == 0 /*&& (sumadelante % n) == 0*/) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (sumaatras % (n % 10) == 0 && (sumadelante % (n%10)) == 0)  {
                return nofinal(n / 10, sumaatras + n % 10,sumadelante);
            }
            else {
                return false;
            }

        }
    }
    

}
long long int aux(long long int n) {
    if (n < 10) {
        return n;
    }
    else {
        return aux(n / 10) + n % 10;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int numero;
    cin >> numero;
    long long int sumadelante = aux(numero);
    bool sol = nofinal(numero,0,sumadelante);
    if (sol == true) {
        cout << "SI" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    // escribir sol


}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}