#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayReverse() {
        displayReverseHelper(top);
        cout << endl;
    }

private:
    void displayReverseHelper(Node* node) {
        if (node == nullptr) return;
        displayReverseHelper(node->next);
        cout << node->data << " ";
    }
};

int main() {
    Stack s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (operation == "pop") {
            s.pop();
        }
    }
    s.displayReverse();
    return 0;
}
/*
Cấu trúc Node:
    data: Lưu giá trị của nút
    next: Con trỏ trỏ đến nút tiếp theo
Cấu trúc Stack:
    top: Con trỏ trỏ đến phần tử đầu tiên của ngăn xếp
Hàm InitializeStack():
    top ← NULL
Giải thích: Biến top được khởi tạo với giá trị NULL, biểu diễn ngăn xếp rỗng.
Độ phức tạp: 𝑂(1)vì chỉ thực hiện gán giá trị.
Hàm Push(Stack, value):
    newNode ← Node(value, NULL)
    newNode.next ← Stack.top
    Stack.top ← newNode
    Giải thích:
Một nút mới được tạo chứa giá trị value.
Con trỏ next của nút mới được trỏ đến nút hiện tại ở đỉnh ngăn xếp (top).
Đỉnh ngăn xếp (top) được cập nhật để trỏ đến nút mới.
Độ phức tạp: 𝑂(1), vì chỉ thực hiện thêm một nút và chỉnh sửa con trỏ.
Hàm Pop(Stack):
Nếu Stack.top = NULL:
Trả về "Ngăn xếp rỗng"
Ngược lại:
temp ← Stack.top
Stack.top ← Stack.top.next
Xóa temp
Giải thích:
Nếu top là NULL, nghĩa là ngăn xếp rỗng.
Nếu không rỗng, nút tại đỉnh ngăn xếp (top) được lưu vào biến tạm thời (temp).
Đỉnh ngăn xếp được cập nhật để trỏ đến nút tiếp theo (top.next).
Nút đã xóa được giải phóng khỏi bộ nhớ.
Độ phức tạp: 𝑂(1), vì chỉ thực hiện xóa một nút và cập nhật con trỏ.
Hàm Display(Stack):
temp ← Stack.top
Trong khi temp ≠ NULL:
In temp.data
temp ← temp.next
Giải thích:
Bắt đầu từ đỉnh ngăn xếp (top), duyệt qua tất cả các nút.
Dữ liệu của từng nút (temp.data) được in ra cho đến khi hết danh sách liên kết.
Độ phức tạp: 𝑂(𝑛), vì cần duyệt qua 𝑛 phần tử trong ngăn xếp.
Hàm DisplayReverse(Stack):
Gọi DisplayReverseHelper(Stack.top)
Hàm DisplayReverseHelper(node):
Nếu node = NULL:
Trả về
DisplayReverseHelper(node.next)
In node.data
Giải thích:
Sử dụng đệ quy để duyệt tới cuối danh sách liên kết (ngăn xếp).
Khi đã đạt đến nút cuối cùng, dữ liệu được in từ cuối về đầu.
Độ phức tạp thời gian: 𝑂(𝑛), vì duyệt qua tất cả 𝑛 phần tử.
Độ phức tạp không gian: 𝑂(𝑛), vì cần 𝑛 khung ngăn xếp cho đệ quy.
*/



