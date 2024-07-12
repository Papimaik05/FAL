// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// función que resuelve el problema
 std::string resolver(std::vector<std::string> v, std::string nombre) {
     int contador = 0;
     bool puede=false;

     for (int i = 0; i < v.size(); i++) {
         if (v[i] == nombre) {
             puede = true;
         }
     }
     if (!puede) {
         return "NUNCA";
     }
     else{
         for (int i = 0; i < v.size(); i++)
         {
             if (v[i] == nombre) {
                 contador = 1;
             }
             else {
                 contador++;
             }

         }
     }

     return std::to_string(contador);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamanoarray;
    std::string buscado;
    std::cin >> tamanoarray;
    if (tamanoarray<1 || tamanoarray>100000) //coste 0
        return false;
  
    std::cin >> buscado;

    std::vector<std::string> vect;
    for (int i = 0; i < tamanoarray; i++) // coste inicial
    {
        std::string pais;
        std::cin >> pais;
        vect.push_back(pais);
    }

    std::string solucion = resolver(vect,buscado);
    std::cout << solucion << std::endl;


    // escribir sol

    return true;

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
