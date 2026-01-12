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
        return new Node(valor);}

    Node* actual = nodo;

    while(actual-> next != nullptr){
        actual= actual -> next;}

    Node* nuevo = new Node(valor);

    actual -> next= nuevo;

    return nodo;
}

bool buscarUnNodo(Node* nodo, int valor){
    
    Node* actual=nodo;

    while(actual!= nullptr){
        if(actual-> data== valor){
            return true;}
        actual=actual-> next;}

    return false;
    
}

Node* eliminarNodo(Node* nodo, int posicion){

    Node* actual= nodo;
    Node* previo = nodo;

    if(nodo== nullptr){
        return nodo;
    }

    if(posicion==1){
        nodo= actual-> next;
        delete actual;
        return nodo;}
    
    for(int i=1; i<posicion; i++){
        previo=actual;
        actual=actual -> next;
    }

    if (actual == nullptr) {
        return nodo;}

    previo->next = actual->next;
    delete actual;

    return nodo;
    
}
