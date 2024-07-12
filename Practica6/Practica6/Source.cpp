// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
//No Final
// Ecuacion recursiva :  
/*

Resolver1(n1,n2)=  {(n1 + n2) %10                                             n1<10 && n2<10
                   {Resolver1(n1/10,n2/10)*10 + c0                  En todos los demás casos (n1>=10||n2>=10) 
*/

int resolver1(int n1,int n2) {
    if (n1<10 && n2<10) {
        return (n1 + n2) % 10;
    }
    else  {
        return resolver1(n1 / 10, n2 / 10) * 10 + (n1 + n2) % 10;
    }

}

//Final

// Ecuacion recursiva :  
  
/*
Resolver2(n1,n2,suma,pot)=  {((n1 + n2) %10) * pot + suma                                         n1<10 && n2<10
                            {Resolver2(n1/10,n2/10,((n1 + n2) %10) * pot + suma,pot*10)           En todos los demás casos (n1>=10||n2>=10)
*/

int resolver2(int n1,int n2,int suma,int pot) {

    if (n1 < 10 && n2 < 10) {
        return  ((n1 + n2) % 10) *pot + suma;
    }
    else {
        return resolver2(n1 / 10, n2 / 10, ((n1 + n2) % 10) *pot + suma, pot * 10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n1, n2;
    cin >> n1;
    cin >> n2;
    int sol1 = resolver1(n1,n2);
    int sol2 = resolver2(n1, n2,0,1);


    cout << sol1 << " " << sol2<<"\n";
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
    /*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/

    return 0;
}