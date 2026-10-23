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
//3.2 busqueda binaria del mayor elemento menor que el objetivo target 
int FindLargestSmallerThanTarget(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1; // Inicializar el resultado como -1 (no encontrado)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            result = arr[mid]; // Actualizar el resultado
            left = mid + 1; // Buscar en la mitad derecha
        } else {
            right = mid - 1; // Buscar en la mitad izquierda
        }
    }

    return result;
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
    //buscar el mayor elemento menor que el objetivo target
    std::cout << "busqueda binaria del mayor elemento menor que el objetivo target=5" << std::endl;
    int target=5;
    int result = FindLargestSmallerThanTarget(arr, sizeof(arr) / sizeof(arr[0]), target);
    if (result != -1) {
        std::cout << "El mayor elemento menor que " << target << " es: " << result << std::endl;
    } else {
        std::cout << "No hay elementos menores que " << target << std::endl;
    }
    //si no existe el mayor elemento menor que el objetivo target, se debe retornar -1
    std::cout << "busqueda binaria del mayor elemento menor que el objetivo target=1" << std::endl;
    target=1;
    result = FindLargestSmallerThanTarget(arr, sizeof(arr) / sizeof(arr[0]), target);
    if (result != -1) {
        std::cout << "El mayor elemento menor que " << target << " es: " << result << std::endl;
    } else {
        std::cout << "No hay elementos menores que " << target <<"entonces:"<<"-1" << std::endl;
    }
    return 0;
}
