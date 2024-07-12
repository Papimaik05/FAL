// Miguel Mateos
// A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
/*
    Espacio de búsqueda: Son todas las soluciones posibles del problema ,que en este caso serían 3^tamaño buscado.De estas soluciones potenciales habrá que
                         quedarse con las soluciones reales,es decir habrá que podar el arbol

    Arbol de exploracion:
                          Numero de ramas: 1 (La del rojo,que luego se va dividiendo en 3 subramas (rojo,verde,azul)
                          Altura: El numero de etapas depende de la altura que estamos buscando

                                      azul
                                azul  rojo
                                      verde

                                      azul
                      rojo      rojo  rojo
                                      verde

                                      azul
                                verde rojo

    Vector solucion = Estara formado por 0 ,1 o 2 siempre empezando por 1 ,el tamaño del vector solución sera como piezas que tenga la torre

*/

void escribirvector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0) {
            cout << "azul ";
        }
        else if (v[i] == 1) {
            cout << "rojo ";
        }
        else if (v[i] == 2) {
            cout << "verde ";
        }
    }
}
// función que resuelve el problema
bool esValida(const vector<int>& v, int i, const vector<int>& acumulados) {
    if (acumulados[2] > acumulados[0]) {
        return false;
    }
    if (v[i - 1] == 2 && v[i]==2) {
        return false;
    }
   
   
    return true;
}
void resolver(int n, int m, int k, vector<int>& v,vector<int> &acumulados,const vector<int> &aux,bool &hay) {
    for (int i = 0; i < n; i++) {
        if (acumulados[i]<aux[i]) {
            v[k] = i;
            acumulados[i]++;
            if (esValida(v, k, acumulados)) {
                if (k == m - 1) {
                    if (acumulados[1] > acumulados[0] + acumulados[2]) {
                        escribirvector(v);
                        cout << "\n";
                        hay = true;
                    }

                }
                else {
                    resolver(n, m, k + 1, v, acumulados,aux,hay);
                }
            }
            acumulados[i]--;
        }  
    }
    
   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano;
    int a, r, ver;
    cin >> tamano >> a >> r >>ver;
    if (tamano == 0 && a==0 && r==0 && ver==0)
        return false;

    vector<int> v(tamano);
    vector<int> acumulado;
    acumulado.assign(3,0);
    vector<int> maxfichas;
    maxfichas.push_back(a);
    maxfichas.push_back(r);
    maxfichas.push_back(ver);
    v[0] = 1;
    acumulado[1]++;
    bool hay = false;
    if (tamano == 1) {
        escribirvector(v);
    }
    else {
        resolver(3, tamano, 1, v,acumulado,maxfichas,hay);
        if (hay == false) {
            cout << "SIN SOLUCION \n";
        }
    }

    // escribir sol

    return true;

}

int main() {

    while (resuelveCaso())
        ;
    return 0;
}
