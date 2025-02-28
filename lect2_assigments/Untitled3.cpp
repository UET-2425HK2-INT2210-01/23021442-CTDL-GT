#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    int count_triplets() {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0;
        }

        int count = 0;
        Node* current = head->next;

        while (current->next != nullptr) {
            if (current->prev->data + current->data + current->next->data == 0) {
                count++;
            }
            current = current->next;
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    DoublyLinkedList dll;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        dll.append(value);
    }

    cout << dll.count_triplets() << endl;

    return 0;
}
