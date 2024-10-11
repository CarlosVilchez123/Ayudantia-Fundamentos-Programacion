# ¿Qué es un grafo?
Un grafo es una estructura de datos compuesta por un conjunto de vértices (también llamados nodos) y un conjunto de aristas que conectan pares de vértices. Formalmente, un grafo 𝐺 se define como un par 𝐺= (𝑉,𝐸) G=(V,E), donde:
- V es el conjunto de vértices.
- E es el conjunto de aristas, donde cada arista conecta dos vértices.

Los grafos pueden representar una gran variedad de sistemas reales como redes sociales, mapas de carreteras, circuitos eléctricos, conexiones de redes, etc.

- **Grafo dirigido**: En un grafo dirigido (o dígrafo), las aristas tienen una dirección, lo que significa que la relación entre dos nodos no es simétrica. Si hay una arista de u a 𝑣, no implica necesariamente que haya una de v a 𝑢.
- **Grafo no dirigido**: En un grafo no dirigido, las aristas no tienen dirección. La conexión entre dos vértices es simétrica, es decir, si hay una arista de u a v, también existe de v a u.
- **Grafo ponderado**: En un grafo ponderado, cada arista tiene un valor o "peso" asociado. Estos pesos pueden representar costos, distancias, tiempos, etc.
- **Grafo no ponderado**: Aquí, las aristas no tienen peso o todos los pesos son iguales.

# Posibles implementaciones de un grafo
Existen varias formas de implementar un grafo en programación. Las dos más comunes son:
1. Lista de Adyacencia
En una lista de adyacencia, cada vértice tiene asociada una lista de los vértices a los que está conectado directamente mediante una arista. Es una representación eficiente en términos de espacio, especialmente para grafos dispersos (es decir, cuando el número de aristas es mucho menor que el número máximo posible de aristas).

Por ejemplo, para un grafo con 5 vértices y las siguientes aristas: 
0↔1,0↔4,1↔2,1↔3,1↔4,2↔3,3↔4

Una lista de adyacencia sería:
```
0 -> 1, 4
1 -> 0, 2, 3, 4
2 -> 1, 3
3 -> 1, 2, 4
4 -> 0, 1, 3
```
Ventajas de la lista de adyacencia:

- Espacio eficiente para grafos dispersos.
- Fácil de agregar nuevas aristas.

Desventajas:
- Es costoso comprobar si una arista existe entre dos vértices, ya que requiere recorrer la lista de adyacencia del vértice.

2. Matriz de Adyacencia
Una matriz de adyacencia es una matriz de n×n, donde n es el número de vértices del grafo. Cada celda de la matriz A[i][j] contiene un valor (generalmente 1 o 0) que indica si existe una arista entre los vértices i y j. En el caso de grafos ponderados, la celda puede contener el valor del peso de la arista.

# Implementacion de C++
```
#include <iostream>
#include <vector>
#include <list>

class Grafo {
    int numVertices;  // Número de vértices en el grafo
    std::vector<std::list<int>> adjList;  // Vector de listas de adyacencia

public:
    // Constructor: inicializa el grafo con un número de vértices
    Grafo(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);  // Redimensiona la lista de adyacencia para que tenga espacio para todos los vértices
    }

    // Método para agregar una arista entre dos vértices
    void agregarArista(int origen, int destino) {
        adjList[origen].push_back(destino);  // Añadir destino a la lista de origen
        adjList[destino].push_back(origen);  // Añadir origen a la lista de destino para grafo no dirigido
    }

    // Mostrar el grafo (lista de adyacencia)
    void mostrarGrafo() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vértice " << i << ":";
            for (int vertice : adjList[i]) {
                std::cout << " -> " << vertice;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Crear un grafo con 5 vértices
    Grafo g(5);

    // Agregar aristas entre los vértices
    g.agregarArista(0, 1);
    g.agregarArista(0, 4);
    g.agregarArista(1, 2);
    g.agregarArista(1, 3);
    g.agregarArista(1, 4);
    g.agregarArista(2, 3);
    g.agregarArista(3, 4);

    // Mostrar el grafo
    std::cout << "Lista de Adyacencia del Grafo:" << std::endl;
    g.mostrarGrafo();

    return 0;
}
```
# Algoritmo DSF
El algoritmo DFS (Depth-First Search), o Búsqueda en Profundidad, es un algoritmo de recorrido en grafos que explora lo más profundo posible en cada camino antes de retroceder y explorar otras ramas. Es un enfoque recursivo o basado en una pila que sigue el principio de "ir tan lejos como se pueda" antes de retroceder.

Funcionamiento del Algoritmo DFS:
- Inicio en un vértice: Se elige un vértice de inicio en el grafo (generalmente proporcionado como entrada), y este vértice es marcado como visitado.

- Recorrido de los adyacentes: Se selecciona un vértice adyacente que no haya sido visitado aún y se aplica DFS recursivamente en él, es decir, se repite el proceso de marcarlo como visitado y explorar sus adyacentes.

- Retroceso: Si el vértice no tiene vértices adyacentes no visitados, se retrocede (en la recursión o en la pila) al vértice anterior y continúa buscando otros vértices adyacentes sin visitar.

- Terminación: El algoritmo finaliza cuando se han visitado todos los vértices alcanzables desde el vértice de inicio. En el caso de que existan componentes desconectados, el DFS debe reiniciarse desde otro vértice no visitado si se desea recorrer todo el grafo.

Etapas Principales del DFS:
- Inicialización: Se inicia el recorrido desde un vértice fuente y se marca como visitado.
- Exploración Recursiva o en Pila: Para cada vértice, el algoritmo recorre todos sus vértices adyacentes no visitados de manera recursiva.
Retroceso: Si no hay más vértices adyacentes no visitados, el algoritmo retrocede para explorar otros caminos.
# Ejemplo de salida
```
Lista de Adyacencia del Grafo:
Vértice 0: -> 1 -> 4
Vértice 1: -> 0 -> 2 -> 3 -> 4
Vértice 2: -> 1 -> 3
Vértice 3: -> 1 -> 2 -> 4
Vértice 4: -> 0 -> 1 -> 3
```

# Ejercicio
Escribe un programa en C++ que implemente un grafo no dirigido utilizando una lista de adyacencia. Luego, implementa el algoritmo de Búsqueda en Profundidad (DFS) para explorar el grafo. El programa debe permitir lo siguiente:

- Agregar vértices y aristas al grafo.
- Realizar la búsqueda DFS desde un vértice inicial, imprimiendo los vértices en el orden en que son visitados.
- Mostrar la lista de adyacencia para visualizar las conexiones del grafo.
# Codigo de ejemplo
```
#include <iostream>
#include <vector>
#include <list>

class Grafo {
    int numVertices;  // Número de vértices en el grafo
    std::vector<std::list<int>> adjList;  // Vector de listas de adyacencia

    // Función auxiliar recursiva para DFS
    void DFSUtil(int vertice, std::vector<bool> &visitado) {
        visitado[vertice] = true;  // Marcamos el vértice como visitado
        std::cout << vertice << " ";  // Imprimimos el vértice visitado

        // Recorremos todos los vértices adyacentes al vértice actual
        for (int adyacente : adjList[vertice]) {
            if (!visitado[adyacente]) {
                DFSUtil(adyacente, visitado);  // Llamada recursiva para el vértice adyacente no visitado
            }
        }
    }

public:
    // Constructor: inicializa el grafo con un número de vértices
    Grafo(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);  // Redimensiona la lista de adyacencia para que tenga espacio para todos los vértices
    }

    // Método para agregar una arista entre dos vértices
    void agregarArista(int origen, int destino) {
        adjList[origen].push_back(destino);  // Añadir destino a la lista de origen
        adjList[destino].push_back(origen);  // Añadir origen a la lista de destino para grafo no dirigido
    }

    // Método para realizar la búsqueda en profundidad (DFS)
    void DFS(int inicio) {
        std::vector<bool> visitado(numVertices, false);  // Vector para marcar los nodos visitados
        DFSUtil(inicio, visitado);  // Llamamos a la función recursiva de DFS
    }

    // Mostrar el grafo (lista de adyacencia)
    void mostrarGrafo() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vértice " << i << ":";
            for (int vertice : adjList[i]) {
                std::cout << " -> " << vertice;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Crear un grafo con 5 vértices
    Grafo g(5);

    // Agregar aristas entre los vértices
    g.agregarArista(0, 1);
    g.agregarArista(0, 4);
    g.agregarArista(1, 2);
    g.agregarArista(1, 3);
    g.agregarArista(1, 4);
    g.agregarArista(2, 3);
    g.agregarArista(3, 4);

    // Mostrar el grafo
    std::cout << "Lista de Adyacencia del Grafo:" << std::endl;
    g.mostrarGrafo();

    // Realizar DFS desde el vértice 0
    std::cout << "\nBúsqueda en Profundidad (DFS) desde el vértice 0:" << std::endl;
    g.DFS(0);

    return 0;
}
```

PseudoCodigo de DFS
```
DFS(Grafo G, Vértice v):
    Crear un conjunto visitado para almacenar los vértices visitados
    Llamar a DFS_Recursivo(G, v, visitado)

DFS_Recursivo(Grafo G, Vértice v, Conjunto visitado):
    Marcar v como visitado
    Imprimir v  // Procesar el vértice actual (opcional)
    
    Para cada vértice u adyacente a v en G:
        Si u no ha sido visitado:
            Llamar a DFS_Recursivo(G, u, visitado)
```

# Reto Determinar la complejidad del algoritmo 
