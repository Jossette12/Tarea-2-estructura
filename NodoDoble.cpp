
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
        return nuevo;}

    Node* actual=nodo;

    while(actual -> next!=nullptr){
        actual=actual -> next;}

    Node* nuevo= new Node(dato);

    actual -> next = nuevo;
    nuevo -> prev = actual;

    return nodo;}

bool buscarUnNodo(Node* nodo, int dato){

    if(nodo== nullptr){
        return false;}

    Node* actual = nodo;

    while(actual!=nullptr){

        if(actual-> data==dato){
            return true;}
        
        actual= actual -> next;}
    
    return false;}

Node* eliminarNodo(Node* nodo, int posicion){

    Node* actual= nodo;

    if(nodo== nullptr){
        return nodo;}

    if(posicion==1){
        nodo= actual-> next;
        nodo -> prev = nullptr;
        delete actual;
        return nodo;}
    
    for(int i=1; i<posicion; i++){
        actual=actual -> next;}

    if (actual == nullptr) {
        return nodo;}
    
     if (actual->prev != nullptr) {
        actual->prev->next = actual->next;}

    if (actual->next != nullptr) {
        actual->next->prev = actual->prev;}

    delete actual;
    return nodo;}
