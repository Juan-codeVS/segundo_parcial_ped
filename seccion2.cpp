            //pilas y colas STL 
            #include <stack>
            #include <queue>
            #include <iostream>
            void eliminar_repetidos_consecutivos(std::stack<int>&pila);
            void SeparateRequests(std::queue<int>& requests,
                std::queue<int>& priority);
            
            int main() {
                //pila stack de enteros 
                std::stack<int> pila;
                
                pila.push(5);
                pila.push(5);
                pila.push(5);
                pila.push(8);
                pila.push(8);
                pila.push(7);
                pila.push(7);
                pila.push(7);

                std::stack<int> copia_pila = pila;
                while (!copia_pila.empty()) {
                    std::cout << copia_pila.top() << " ";
                    copia_pila.pop();
                }
                std::cout << std::endl;
                eliminar_repetidos_consecutivos(pila);

                //cola de solicitudes de enteros
                std::cout << "cola de solicitudes" << std::endl;
                std::queue<int> cola;
                cola.push(4);
                cola.push(6);
                cola.push(8);
                cola.push(10);
                cola.push(12);
                cola.push(14);
                cola.push(9);
                // Imprimir la cola de solicitudes
                std::cout << "Contenido de la cola:" << std::endl;
                std::queue<int> copia_cola = cola;
                while (!copia_cola.empty()) {
                    std::cout << copia_cola.front() << " ";
                    copia_cola.pop();
                }
                std::cout << std::endl;

                std::queue<int> prioridad;
                SeparateRequests(cola, prioridad);
                std::cout << "Solicitudes restantes:" << std::endl;
                while (!cola.empty()) {
                    std::cout << cola.front() << " ";
                    cola.pop();
                }
                std::cout << std::endl;
                return 0;
            }
            //funcion para eliminar elementos repetidos consecutivamente desde el tope hacia el fondo,conservar al menos 1 elemento consecutivo
            void eliminar_repetidos_consecutivos(std::stack<int>& pila) {
                
                // Eliminar elementos repetidos consecutivos
                std::stack<int> pila_final;
                while (!pila.empty()) {
                    int actual = pila.top();
                    pila.pop();

                    if (pila_final.empty() || pila_final.top() != actual) {
                        pila_final.push(actual);
                    }
                }
                // Devolver los elementos de la pila final a la pila original
                while (!pila_final.empty()) {
                    pila.push(pila_final.top());
                    pila_final.pop();
                }
                //im[rimir la pila resultante
                std::cout << "Pila resultante (de cima a base):" << std::endl;
                while (!pila.empty()) {
                    std::cout << pila.top() << std::endl;
                    pila.pop();
                }
            }
            void SeparateRequests(
                std::queue<int>& requests,
                std::queue<int>& priority) {
            //separar las solicitudes que son multiplo de 3  y mover a otra cola de prioridad
                std::queue<int> tempQueue;
                while (!requests.empty()) {
                    int request = requests.front();
                    requests.pop();
                    if (request % 3 == 0) {
                        priority.push(request);
                    } else {
                        tempQueue.push(request);
                    }
                }
                // Mover las solicitudes restantes de vuelta a la cola original
                while (!tempQueue.empty()) {
                    requests.push(tempQueue.front());
        tempQueue.pop();
    }
    // Imprimir la cola de prioridad
    std::cout << "Cola de prioridad (múltiplos de 3):" << std::endl;
    while (!priority.empty()) {
        std::cout << priority.front() << " ";
        priority.pop();
    }
    std::cout << std::endl;
}