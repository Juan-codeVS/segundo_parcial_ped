#include <iostream>
#include <string>
//segundo parcial de PED seccion 1 xd
struct node{  
int data;
  node* next;
  node* prev;
};
//funcion intercambia fisicamente los nodos adyacentes  de dos en dos  comenzando desde el primer nodo de la lista.
void swap_adjacent_nodes(node*& head) {
  if (head == nullptr || head->next == nullptr) {
    return; // No hay nodos para intercambiar
  }

  node* current = head;
  node* new_head = head->next; // El nuevo head será el segundo nodo

  while (current != nullptr && current->next != nullptr) {
    node* next_node = current->next;
    node* next_next_node = next_node->next;

    // Intercambiar los nodos
    next_node->prev = current->prev;
    current->next = next_next_node;
    current->prev = next_node;
    next_node->next = current;

    if (next_next_node != nullptr) {
      next_next_node->prev = current;
    }

    // Mover al siguiente par de nodos
    current = next_next_node;
  }

  head = new_head; // Actualizar el head de la lista
   delete new_head;
}
//La lista tiene un puntero head que apunta al primer nodo. El último nodo tiene next == nullptr y el primero tiene prev == nullptr.
int main() {
  node* head = nullptr; 
  // Crear el primer nodo
  head = new node;
  head->data = 10;
  head->next = nullptr;
  head->prev = nullptr;

  // Crear el segundo nodo
  node* second = new node;
  second->data = 20;
  second->next = nullptr;
  second->prev = head; // El segundo nodo apunta al primero
  head->next = second; // El primer nodo apunta al segundo

  // Crear el tercer nodo
  node* third = new node;
  third->data = 30;
  third->next = nullptr;
  third->prev = second; // El tercer nodo apunta al segundo
  second->next = third; // El segundo nodo apunta al tercero

    node* fourth = new node;
  fourth->data = 40;
    fourth->next = nullptr;
    fourth->prev = third; // El cuarto nodo apunta al tercero
    third->next = fourth; // El tercer nodo apunta al cuarto

  // Imprimir la lista desde el principio hasta el final
  node* current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;

  // Imprimir la lista desde el final hasta el principio
  current = fourth;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->prev;
  }
  std::cout << std::endl;
 swap_adjacent_nodes(head);
  // Imprimir la lista desde el principio hasta el final después del intercambio
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    // Liberar memoria
  delete third;
  delete second;
  delete head;
  delete fourth;
  delete current;
  return 0;
}