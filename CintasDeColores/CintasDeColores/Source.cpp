//Miguel Mateos
//A50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



// función que resuelve el problema
void resolver(vector<pair<char, int>> &v,int &i,int &j) {
    int k = 0;
    i = 0;
    j = v.size() - 1;
    while (k <= j) {

        if(v[k].first=='a'){
            swap(v[i],v[k]);
            i++;
            k++;
        }
        else if (v[k].first == 'v') {
            k++;
        }
        else if (v[k].first == 'r' ) {
            swap(v[j], v[k]);            
             j--;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamano,valor;
    char color;
    vector<pair<char,int>> v;
    cin >> tamano;
    if (!std::cin)
        return false;
    for (int i = 0; i < tamano ; i++)
    {
        cin >> color;
        cin >> valor;

        v.push_back({color,valor});
        
    }
    int ix, jx;
    resolver(v,ix,jx);


    sort(v.begin(), v.begin() + ix);

    sort(v.begin() + ix, v.begin() + 1 + jx);
    sort(v.begin() + 1 + jx, v.end());

    cout << "AZULES" << " : ";
    for (int i = 0; i < ix; i++)
    {
        cout << v[i].second<<" ";
    }
    cout << "\n";
    cout << "VERDES" << " : ";
    for (int i = ix; i <= jx; i++)
    {
        cout << v[i].second << " ";
    }

    cout << "\n";
    cout << "Rojas" << " : ";
    for (int i = jx+1; i < v.size(); i++)
    {
        cout << v[i].second << " ";
    }
    cout << "\n";

    // escribir sol


    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}