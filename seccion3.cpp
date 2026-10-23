//ejercicio 3.1 ordenamiento por prioridad
#include <iostream>
#include <algorithm>
//algoritmo que ordena por numeros pares primero y luego impares void InsertionSort(int arr[], int n)
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mover los elementos mayores que key hacia adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    //ordenar numeros pares primero y luego impares
    std::stable_partition(arr, arr + n, [](int x) { return x % 2 == 0; });
    //imprimir el arreglo ordenado
    std::cout << "Arreglo ORDENADO: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    //arreglo de enteros
    int arr[] = { 5, 2, 9, 1, 5, 6,7,8,3,4 };
    //imprimir el arreglo original
    std::cout << "Arreglo INICIAL: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}