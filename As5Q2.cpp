#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

int deleteKeyOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }
    return count;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertAtEnd(1); insertAtEnd(2); insertAtEnd(1); insertAtEnd(2);
    insertAtEnd(1); insertAtEnd(3); insertAtEnd(1);

    cout << "Original List: "; display();

    int key = 1;
    int cnt = deleteKeyOccurrences(key);

    cout << "Count: " << cnt << endl;
    cout << "Updated List: "; display();
}
