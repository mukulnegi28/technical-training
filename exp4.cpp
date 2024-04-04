#include <iostream>
using namespace std;

// Structure for the linked list node
struct Node {
    int value;
    Node* next;
};


Node* insertNodeAtBeginning(Node* head, int val) {
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    return newNode;
}


void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int numElements, elementValue;
    cout << "Enter the number of elements to be inserted at the beginning: ";
    cin >> numElements;

    Node* head = nullptr;

    for (int i = 0; i < numElements; i++) {
        cout << "Enter the element to be inserted: ";
        cin >> elementValue;
        head = insertNodeAtBeginning(head, elementValue);
    }

    cout << "Linked List after insertion: ";
    printLinkedList(head);

    return 0;
}