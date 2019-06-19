#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *xorreference;
};

Node *XOR(Node *left, Node *right) {
    return (Node *) ((uintptr_t)left ^ (uintptr_t)right);
}

void insert(Node **root, int data) {
    Node *new_node = new Node();
    new_node->data = data;

    new_node->xorreference = XOR(*root, NULL);

    if(*root != NULL) {
        Node *next = XOR((*root)->xorreference, NULL);
        (*root)->xorreference = XOR(new_node, next);
    }

    *root = new_node;
}

void print(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    while(curr != NULL) {
        cout << curr->data << " ";

        next = XOR(prev, curr->xorreference);

        prev = curr;
        curr = next;
    } 
}

int main() {
    Node *head = NULL;

    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    print(head);

    return(0);
}
