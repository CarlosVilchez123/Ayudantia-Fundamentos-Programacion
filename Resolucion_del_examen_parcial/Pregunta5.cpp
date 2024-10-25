#include <iostream>
using namespace std;

// Función para intercambiar el i-ésimo bit de dos variables unsigned
void swap_bits(unsigned int &var1, unsigned int &var2, unsigned int i) {
    // Obtenemos el i-ésimo bit de ambas variables
    unsigned int bit1 = (var1 >> i) & 1;
    unsigned int bit2 = (var2 >> i) & 1;
    
    // Si los bits son diferentes, hacemos el intercambio
    if (bit1 != bit2) {
        // Cambiamos el i-ésimo bit de var1
        var1 ^= (1 << i);  // Usamos XOR para invertir el bit en la posición i
        // Cambiamos el i-ésimo bit de var2
        var2 ^= (1 << i);  // Usamos XOR para invertir el bit en la posición i
    }
}

int main() {
    unsigned int var1, var2;
    unsigned int i;

    // Ingreso de las variables
    cout << "Ingrese la primera variable (unsigned int): ";
    cin >> var1;
    cout << "Ingrese la segunda variable (unsigned int): ";
    cin >> var2;
    cout << "Ingrese el valor de i (bit a intercambiar): ";
    cin >> i;

    // Mostrar antes de intercambiar
    cout << "Antes de intercambiar:" << endl;
    cout << "var1: " << var1 << ", var2: " << var2 << endl;

    // Llamamos a la función para intercambiar los bits
    swap_bits(var1, var2, i);

    // Mostrar después de intercambiar
    cout << "Despues de intercambiar:" << endl;
    cout << "var1: " << var1 << ", var2: " << var2 << endl;

    return 0;
}
