### Ejercicios Nivel Facil
1. **Ejercicio 1:**
   Calcula la complejidad temporal del siguiente fragmento de código:
   ```python
   for i in range(n):
       print(i)
   ```
   **Respuesta:** $$O(n)$$

2. **Ejercicio 2:**
   Determina la complejidad espacial del siguiente código:
   ```python
   def create_list(n):
       return [i for i in range(n)]
   ```
   **Respuesta:** $$O(n)$$

3. **Ejercicio 3:**
   ¿Cuál es la complejidad temporal de acceder a un elemento en una lista por su índice?
   ```python
   lista = [1, 2, 3, 4, 5]
   elemento = lista[2]
   ```
   **Respuesta:** $$O(1)$$

### Ejercicios de Nivel Medio
4. **Ejercicio 4:**
   Calcula la complejidad temporal del siguiente fragmento de código:
   ```python
   for i in range(n):
       for j in range(n):
           print(i, j)
   ```
   **Respuesta:** $$O(n^2)$$

5. **Ejercicio 5:**
   Determina la complejidad temporal del siguiente algoritmo de búsqueda binaria:
   ```python
   def binary_search(arr, x):
       low = 0
       high = len(arr) - 1
       while low <= high:
           mid = (low + high) // 2
           if arr[mid] < x:
               low = mid + 1
           elif arr[mid] > x:
               high = mid - 1
           else:
               return mid
       return -1
   ```
   **Respuesta:** $$O(\log n)$$

6. **Ejercicio 6:**
   ¿Cuál es la complejidad temporal de la siguiente función recursiva?
   ```python
   def factorial(n):
       if n == 0:
           return 1
       else:
           return n * factorial(n-1)
   ```
   **Respuesta:** $$O(n)$$

7. **Ejercicio 7:**
   Calcula la complejidad temporal del siguiente código:
   ```python
   for i in range(n):
       for j in range(i):
           print(i, j)
   ```
   **Respuesta:** $$O(n^2)$$

8. **Ejercicio 8:**
   Determina la complejidad espacial del siguiente código:
   ```python
   def create_matrix(n):
       return [[0] * n for _ in range(n)]
   ```
   **Respuesta:** $$O(n^2)$$

### Ejercicios Muy Difíciles
9. **Ejercicio 9:**
   Calcula la complejidad temporal del siguiente algoritmo de ordenamiento:
   ```python
   def quicksort(arr):
       if len(arr) <= 1:
           return arr
       pivot = arr[len(arr) // 2]
       left = [x for x in arr if x < pivot]
       middle = [x for x in arr if x == pivot]
       right = [x for x in arr if x > pivot]
       return quicksort(left) + middle + quicksort(right)
   ```
   **Respuesta:** $$O(n \log n)$$ en promedio, $$O(n^2)$$ en el peor caso.

10. **Ejercicio 10:**
    Determina la complejidad temporal del siguiente algoritmo de búsqueda en un árbol binario de búsqueda (BST):
    ```python
    def search_bst(root, key):
        if root is None or root.val == key:
            return root
        if root.val < key:
            return search_bst(root.right, key)
        return search_bst(root.left, key)
    ```
    **Respuesta:** $$O(h)$$, donde $$h$$ es la altura del árbol. En el peor caso, $$h = n$$ (árbol desbalanceado), y en el mejor caso, $$h = \log n$$ (árbol balanceado).
