#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
    Node* prev;
    Node(int x, int p) : data(x), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp != nullptr && temp->priority >= p) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                Node* last = head;
                while (last->next != nullptr) {
                    last = last->next;
                }
                last->next = newNode;
                newNode->prev = last;
            } else if (temp == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void printQueue() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->data << ", " << temp->priority << ")";
            if(temp->next != nullptr){
                cout << "; ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;
    string command;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }
    pq.printQueue();
    return 0;
}

