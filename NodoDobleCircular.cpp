#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* agregarNodoAlFinal(Node* nodo, int dato){

    if(nodo==nullptr){
        Node* nuevo= new Node(dato);
        nuevo->next = nuevo;
        nuevo->prev = nuevo;
        return nuevo;}

    Node* actual=nodo;

    while(actual -> next!=nodo){
        actual=actual -> next;}

    Node* nuevo= new Node(dato);

    actual -> next = nuevo;
    nuevo -> prev = actual;
    nuevo -> next= nodo;
    nodo-> prev = nuevo;

    return nodo;}


bool buscarUnNodo(Node* nodo, int dato){

    if(nodo== nullptr){
        return false;}

    Node* actual = nodo;

    do{
        if(actual-> data==dato){
            return true;}
        
        actual= actual -> next;}while(actual!=nodo);
    return false;}

Node* eliminarNodo(Node* nodo, int posicion){

    if (nodo == nullptr) {
        return nullptr;}

    if (nodo->next == nodo && posicion == 1) {
        delete nodo;
        return nullptr;}

    Node* actual = nodo;

    if (posicion == 1) {

        Node* ultimo = nodo->prev;
        ultimo->next = nodo->next;
        nodo->next->prev = ultimo;

        Node* temp = nodo;
        nodo = nodo->next;
        delete temp;
        return nodo;}

    for (int i = 1; i < posicion; i++) {
        actual = actual->next;

        if (actual == nodo) {
            return nodo;}}

    actual->prev->next = actual->next;
    actual->next->prev = actual->prev;
    delete actual;
    return nodo;}

