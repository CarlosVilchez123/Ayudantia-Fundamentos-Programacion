#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_CORREDORES = 30;

struct Corredor {
    string nombre;
    int tiempo; // Tiempo en segundos
};

// Función para ingresar los datos de los corredores
void ingresarDatos(Corredor corredores[], int &numCorredores) {
    cout << "Ingrese el numero de corredores (maximo " << MAX_CORREDORES << "): ";
    cin >> numCorredores;
    
    for (int i = 0; i < numCorredores; i++) {
        cout << "Nombre del corredor " << i + 1 << ": ";
        cin >> corredores[i].nombre;
        cout << "Tiempo del corredor " << i + 1 << " (en segundos): ";
        cin >> corredores[i].tiempo;
    }
}

// Función para comparar corredores según su tiempo (usada para ordenar)
bool compararTiempos(const Corredor &a, const Corredor &b) {
    return a.tiempo < b.tiempo;
}

// Función para generar el ranking ordenado por tiempo
void generarRanking(Corredor corredores[], int numCorredores) {
    sort(corredores, corredores + numCorredores, compararTiempos);
    cout << "\nRanking de corredores:" << endl;
    for (int i = 0; i < numCorredores; i++) {
        cout << i + 1 << ". " << corredores[i].nombre << " - " << corredores[i].tiempo << " segundos" << endl;
    }
}

// Función para buscar un corredor por nombre
void buscarCorredor(Corredor corredores[], int numCorredores, string nombreBuscado) {
    for (int i = 0; i < numCorredores; i++) {
        if (corredores[i].nombre == nombreBuscado) {
            cout << nombreBuscado << " esta en la posicion " << i + 1 << " del ranking con un tiempo de " << corredores[i].tiempo << " segundos." << endl;
            return;
        }
    }
    cout << "Corredor no encontrado." << endl;
}

// Función para buscar corredores en un rango de tiempos
void buscarCorredoresEnRango(Corredor corredores[], int numCorredores, int tiempoMin, int tiempoMax) {
    cout << "\nCorredores con tiempos entre " << tiempoMin << " y " << tiempoMax << " segundos:" << endl;
    bool encontrado = false;
    for (int i = 0; i < numCorredores; i++) {
        if (corredores[i].tiempo >= tiempoMin && corredores[i].tiempo <= tiempoMax) {
            cout << corredores[i].nombre << " - " << corredores[i].tiempo << " segundos" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron corredores en ese rango de tiempos." << endl;
    }
}

int main() {
    Corredor corredores[MAX_CORREDORES];
    int numCorredores;
    
    // Ingresar datos de los corredores
    ingresarDatos(corredores, numCorredores);
    
    // Generar y mostrar el ranking
    generarRanking(corredores, numCorredores);
    
    // Buscar un corredor por su nombre
    string nombreBuscado;
    cout << "\nIngrese el nombre del corredor que desea buscar: ";
    cin >> nombreBuscado;
    buscarCorredor(corredores, numCorredores, nombreBuscado);
    
    // Buscar corredores en un rango de tiempos
    int tiempoMin, tiempoMax;
    cout << "\nIngrese el rango de tiempos para buscar corredores." << endl;
    cout << "Tiempo minimo: ";
    cin >> tiempoMin;
    cout << "Tiempo maximo: ";
    cin >> tiempoMax;
    buscarCorredoresEnRango(corredores, numCorredores, tiempoMin, tiempoMax);
    
    return 0;
}
