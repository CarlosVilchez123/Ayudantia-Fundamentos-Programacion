#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definimos las dimensiones máximas
const int MAX = 5;

// Función para llenar un tensor de forma aleatoria con valores entre 1 y 10
void completarTensor(int **tensor, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tensor[i][j] = rand() % 10 + 1; // Generar valores aleatorios entre 1 y 10
        }
    }
}

// Función para imprimir un tensor
void imprimirTensor(int **tensor, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << tensor[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para calcular el producto tensorial
void productoVectorial(int **A, int filasA, int colA, int **B, int filasB, int colB, int ***C) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < colA; j++) {
            for (int k = 0; k < filasB; k++) {
                for (int l = 0; l < colB; l++) {
                    (*C)[i * filasB + k][j * colB + l] = A[i][j] * B[k][l];
                }
            }
        }
    }
}

int main() {
    srand(time(0)); // Semilla para números aleatorios
    
    // Dimensiones de los tensores A y B
    int filasA, colA, filasB, colB;
    
    // Pedir al usuario las dimensiones de los tensores
    cout << "Ingrese las dimensiones de A (filas y columnas): ";
    cin >> filasA >> colA;
    cout << "Ingrese las dimensiones de B (filas y columnas): ";
    cin >> filasB >> colB;

    // Reservar memoria para los tensores A, B y C
    int **A = new int*[filasA];
    for (int i = 0; i < filasA; i++)
        A[i] = new int[colA];

    int **B = new int*[filasB];
    for (int i = 0; i < filasB; i++)
        B[i] = new int[colB];

    int filasC = filasA * filasB;
    int colC = colA * colB;

    int **C = new int*[filasC];
    for (int i = 0; i < filasC; i++)
        C[i] = new int[colC];

    // Completar A y B con valores aleatorios
    completarTensor(A, filasA, colA);
    completarTensor(B, filasB, colB);

    // Imprimir los tensores A y B
    cout << "Tensor A:" << endl;
    imprimirTensor(A, filasA, colA);

    cout << "Tensor B:" << endl;
    imprimirTensor(B, filasB, colB);

    // Calcular el producto tensorial de A y B
    productoVectorial(A, filasA, colA, B, filasB, colB, &C);

    // Imprimir el tensor C (resultado del producto tensorial)
    cout << "Producto tensorial C = A ⊗ B:" << endl;
    imprimirTensor(C, filasC, colC);

    // Liberar la memoria utilizada
    for (int i = 0; i < filasA; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < filasB; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < filasC; i++)
        delete[] C[i];
    delete[] C;

    return 0;
}
