// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
typedef struct {
    long long int n1; //suma actual
    long long int n2; //anterior
}tsol;

long long int multiple(long long int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return multiple(n - 1) + multiple(n - 2);
    }

}

tsol simple(long long int n) {
    if (n == 0) {
        return { 0,0 };
    }
    else if (n == 1) {
        return { 1,0 };
    }
    else {
        tsol aux = simple(n - 1);
        return { aux.n1 + aux.n2,aux.n1 };
    }
}

long long int simple2(long long int n, long long int n1, long long int n2) {
    if (n == 0) {
        return n2;
    }
    else if (n == 1) {
        return n1;
    }
    else {
        return simple2(n - 1, n1 + n2, n1);
    }
}
long long int simple3(long long int n, long long int x, long long int n1, long long int n2){
    if (n == x) {
        return n2;
    }
    else{
        return simple3(n,x+1,n1+n2,n1);
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

    //long long int sol = multiple(numero);
    //tsol sol2 = simple(numero);
    //long long int sol3 = simple2(numero,1,0);
    long long int sol4 = simple3(numero,0,1,0);

    cout << sol4 << "\n";
    // escribir sol


    return true;

}

int main() {
    while (resuelveCaso())
        ;
    return 0;
}