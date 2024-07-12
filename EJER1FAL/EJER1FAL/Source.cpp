﻿// Miguel Mateos Matias
// A50


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int puntuacion;
    int contador=0;
    int max;

    std::cin >> puntuacion;
    max = puntuacion;
    while (puntuacion!=0)  //coste n
    {

        if (max == puntuacion) {
            contador++;
        }
        else if(max < puntuacion){
            contador=1;
            max = puntuacion;

        }
        std::cin >> puntuacion;
    }
    std::cout << max <<" "<<contador << "\n";
 
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif*/ 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}