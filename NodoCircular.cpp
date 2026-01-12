#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* agregarNodoAlFinal(Node* nodo, int valor){

    if (nodo == nullptr) {
        Node* nuevo= new Node(valor);
        nuevo -> next= nuevo;
        return nuevo;
    }

    Node* actual = nodo;

    while(actual-> next != nodo){
        actual= actual -> next;}

    Node* nuevo = new Node(valor);

    actual -> next= nuevo;
    nuevo-> next= nodo;

    return nodo;
}

bool buscarUnNodo(Node* nodo, int valor){

    if (nodo == nullptr) {
        return false;}

    Node* actual = nodo;

    do {
        if (actual->data == valor) {
            return true;}
            
        actual = actual->next;
    } while (actual != nodo);

    return false;
}

Node* eliminarNodo(Node* nodo, int posicion){

    if (nodo == nullptr) {
        return nullptr;}

    if (nodo->next == nodo && posicion == 1) {
        delete nodo;
        return nullptr;}

    Node* actual = nodo;
    Node* previo = nullptr;

    if (posicion == 1) {

        while (actual->next != nodo) {
            actual = actual->next;}

        Node* temp = nodo;
        actual->next = nodo->next;
        nodo = nodo->next;
        delete temp;

        return nodo;}

    actual = nodo;
    
    for (int i = 1; i < posicion; i++) {
        previo = actual;
        actual = actual->next;

        if (actual == nodo) {
            return nodo;}}

    previo->next = actual->next;
    delete actual;

    return nodo;}
