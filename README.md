# Algoritmo de Karatsuba
El algoritmo de karatsuba es un método eficiente para multiplicar números muy grandes. 
Fue desarrollado por Anatolii Karatsuba en 1960 y es uno de los primeros algoritmos que demostro ser más rapido que el método tradicional de multiplicación.

# ¿Cómo funciona el algoritmo?
El algoritmo de Karatsuba se basa en la tecnica de **divide y venceras**. En lugar de multiplicar dos números grandes directamnte, los divide en partes más pequeñas y realiza multiplicaciones más simples.

# Algoritmo
1. **Division:** divide cada número en dos partes de igual tamaño.
2. **Multiplicacion Recursiva:** Realiza tres multiplicaciones recursivas en lugar de cuatro(que sera el caso en la multiplicación tradicional).
3. **Combinacion:** Combina los resultados de las multiplicaciones recursivas para obtener el resultados final.
# Ejemplo 
Supongamos que queremos separar dos números grandes (X) y (Y). Los dividimos en dos partes:
X -> x1 * 10^m + x0
Y -> y1 * 10^m + y0

Donde (x1) y (x0) son las partes de (X), y (y1) y (y0) son las partes de (Y). Luego, calculamos:
```
z0 = x0 * y0
z2 = x1 * y1
Z1 = (x1+x0) * (y1*y0) - z2 -z0
```
Finalmente, combianmos estos resultados:

```
XY = z2 * 10^2m + z1 * 10^m + z0
```

# Implicancia en los algoritmos de Divide y Vencerás
El algoritmo de Karatsuba es un excelente ejemplo de la técnica de divide y vencerás, que es una estrategia fundamental en la informática. Esta técnica implica dividir un problema en subproblemas más pequeños, resolver esos subproblemas de manera recursiva y luego combinar sus soluciones para resolver el problema original.

El algoritmo de Karatsuba reduce la complejidad de tiempo de la multiplicación de (O(n^2)) a (O(n^{\log_2 3})). Esto lo hace mucho más eficiente para multiplicar números grandes, especialmente cuando se compara con el método tradicional.

# PSEUDOCODIGO
```
// Pseudocódigo del algoritmo de Karatsuba

// Función principal de Karatsuba
KaratsubaMultiplicacion(X, Y):
    // Caso base: si los números son lo suficientemente pequeños, usa la multiplicación tradicional
    if (X < 10) or (Y < 10):
        return X * Y

    // Calcula el tamaño de los números
    n = max(longitud(X), longitud(Y))
    m = n / 2

    // Divide los números en partes
    X1 = parteSuperior(X, m)
    X0 = parteInferior(X, m)
    Y1 = parteSuperior(Y, m)
    Y0 = parteInferior(Y, m)

    // Realiza las tres multiplicaciones recursivas
    Z2 = KaratsubaMultiplicacion(X1, Y1)
    Z0 = KaratsubaMultiplicacion(X0, Y0)
    Z1 = KaratsubaMultiplicacion(X1 + X0, Y1 + Y0) - Z2 - Z0

    // Combina los resultados
    return (Z2 * 10^(2*m)) + (Z1 * 10^m) + Z0

// Función para obtener la parte superior de un número
parteSuperior(X, m):
    return X // 10^m

// Función para obtener la parte inferior de un número
parteInferior(X, m):
    return X % 10^m
```
