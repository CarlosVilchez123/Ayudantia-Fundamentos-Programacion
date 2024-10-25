#include <iostream>
#include <cstring> // Para manejar cadenas de caracteres

using namespace std;

// Función para cifrar el texto usando el cifrado César
void cifrarCesar(char *texto, int desplazamiento) {
    while (*texto) {
        if (*texto >= 'a' && *texto <= 'z') {
            // Cifrar solo letras minúsculas
            *texto = (*texto - 'a' + desplazamiento) % 26 + 'a';
        }
        // Los espacios y caracteres fuera del rango [a-z] se mantienen iguales
        texto++;
    }
}

// Función para decodificar el texto usando el cifrado César
void decifrarCesar(char *texto, int desplazamiento) {
    while (*texto) {
        if (*texto >= 'a' && *texto <= 'z') {
            // Decifrar solo letras minúsculas
            *texto = (*texto - 'a' - desplazamiento + 26) % 26 + 'a';
        }
        // Los espacios y caracteres fuera del rango [a-z] se mantienen iguales
        texto++;
    }
}

int main() {
    char texto[101]; // Arreglo para almacenar el texto (máximo 100 caracteres)
    int desplazamiento;
    char opcion;

    // Solicitar el texto al usuario
    cout << "Ingrese el texto (solo letras minusculas y espacios, maximo 100 caracteres): ";
    cin.getline(texto, 101); // Leer la línea completa con espacios

    // Solicitar el desplazamiento
    cout << "Ingrese el valor de desplazamiento: ";
    cin >> desplazamiento;

    // Preguntar si se desea cifrar o decifrar
    cout << "¿Desea cifrar (c) o decifrar (d)? ";
    cin >> opcion;

    if (opcion == 'c') {
        cifrarCesar(texto, desplazamiento);
        cout << "Texto cifrado: " << texto << endl;
    } else if (opcion == 'd') {
        decifrarCesar(texto, desplazamiento);
        cout << "Texto decifrado: " << texto << endl;
    } else {
        cout << "Opcion invalida." << endl;
    }

    return 0;
}
