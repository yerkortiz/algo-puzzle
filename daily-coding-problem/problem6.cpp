/*
 * Good morning! Here's your coding interview problem for today.
 *
 * This problem was asked by Google.
 * An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
 *
 * If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
 */
#include <iostream>

struct Node{
  int value;
  Node* nav_ptr;
};

Node* NavXOR(Node* current, Node* prev){
  return (Node *) ((uintptr_t) current ^ (uintptr_t) prev);
}

void Traverse(Node* current, Node* prev = nullptr) {
  if(current == nullptr) {
    return;
  }
  std::cout<<current -> value<< ' ';
  Traverse(NavXOR(current -> nav_ptr, prev), current);
}

//Insert at the end.
void Add(Node* &current, int value, Node* prev = nullptr) {
  if(current == nullptr) {
    Node* new_node = new Node();
    new_node -> value = value;
    new_node -> nav_ptr = NavXOR(new_node ->nav_ptr, (Node *)prev);
    current = new_node;
    if(prev != nullptr) {
      prev -> nav_ptr = NavXOR(prev -> nav_ptr, (Node*) nullptr);
      prev -> nav_ptr = NavXOR(prev -> nav_ptr, current);
    }
    return;
  }
  Node *next = NavXOR(current -> nav_ptr, prev);
  Add(next, value, current);
}

//Get node value at index.
int Get(Node* current, int index, Node* prev = nullptr, int current_index = 0) {
  if(current == nullptr){
    return -1;
  } else if(current_index == index) {
    return current -> value;
  }
  current_index++;
  return Get(NavXOR(current -> nav_ptr, prev), index, current, current_index);
}
int main() {
  Node* head = nullptr;
  Add(head, 1);
  Traverse(head); 
  std::cout<<'\n';
  Add(head, 2);
  Traverse(head);
  std::cout<<'\n';
  Add(head, 3);
  Traverse(head);
  std::cout<<'\n';
  std::cout<<Get(head, 20);
  return 0;
}
