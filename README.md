# segundo_parcial_ped
segunda parcial de programacion de estructuras dinamicas
preguntas :
### Ejercicio 4.1

Analice el siguiente código:

```
int CountMatches(const int values[], int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (values[i] == j) {
        count++;
      }
    }
  }

  return count;
}
```

Responda:

1. ¿Cuál es la complejidad temporal Big-O?
la compejidad es de O(log n) porque se pasa por cada elemento  cada uno 3 vesces
2. Si `n` se duplica, ¿cómo cambia aproximadamente el número de comparaciones?
si n = 1 el numero de comparaciones es 3 si n =2 el numero de compraciones es 3 si n vale 4 el numero de comparaciones es 12 entonces  el numero de compraciones cambia en funcion de 3n