#include <iostream>
#include <cmath>
using namespace std;

class node {
public:
    int value;
    node* next;

    node(int data){
        value = data;
        next = nullptr;
    }
};

void insertAtBack(node* &head, int val) {
    node* n = new node(val);
    
    if(head == nullptr)
        head = n;
    
    else {
        node* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }

}

void insertAtFront(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

void deleteNode(node* &head, int pos) {
    if(pos == 0) {
        node* todelete = head;
        head = head->next;
        delete todelete; // to free the memory occupied by the node.
        return;
    }

    node* pointer = head;
    for(int i = 0; i < pos-1; i++) pointer = pointer->next;

    node* todelete = pointer->next;
    pointer->next = pointer->next->next;
    delete todelete; // to free the memory occupied by the node.
}

void display(node* head) {
    while(head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main(void) {

    node* head = nullptr;
    insertAtBack(head, 1);
    insertAtBack(head, 4);
    insertAtBack(head, 5);
    insertAtBack(head, 7);

}
