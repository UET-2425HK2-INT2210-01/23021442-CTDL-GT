#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < p - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(int p) {
        if (head == nullptr) {
            return;
        }

        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < p - 1; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        int p, x;
        cin >> operation >> p;
        if (operation == "insert"){
            cin >> x;
            list.insert(p, x);
        } else if (operation == "delete"){
            list.remove(p);
        }
    }

    list.print();
    return 0;
}
