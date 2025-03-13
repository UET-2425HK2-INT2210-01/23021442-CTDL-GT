#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int search(int x) {
        Node* temp = head;
        int position = 0;
        while (temp != nullptr) {
            if (temp->data == x) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    string command;
    vector<int> searchResults;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            int result = list.search(x);
            searchResults.push_back(result);
        } else if (command == "reverse") {
            list.reverse();
        }
    }

    for (int result : searchResults) {
        if (result != -1) {
            cout << result << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    list.print();
    return 0;
}
