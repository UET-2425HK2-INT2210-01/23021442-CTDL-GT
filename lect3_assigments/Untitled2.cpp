#include <iostream>
using namespace std;

long long tinh2MuN_Lap(int n) {
    long long ketQua = 1;
    for (int i = 0; i < n; i++) {
        ketQua *= 2;
    }
    return ketQua;
}

int main() {
    int n;
    cin >> n;

    cout << tinh2MuN_Lap(n) << endl;

    return 0;
}
/*
Biến ketQua được khởi tạo với giá trị 1, vì bất kỳ số nào nhân với 1 đều giữ nguyên.

Vòng lặp for chạy từ 0 đến 𝑛−1
 (tổng cộng 𝑛 lần).
Trong mỗi bước lặp, giá trị hiện tại của ketQua được nhân với 2, mô phỏng quá trình nhân lũy thừa.
Sau khi vòng lặp kết thúc, giá trị cuối cùng của ketQua là 2^𝑛, và hàm trả về kết quả này.
Độ phức tạp:

Thời gian: 𝑂(𝑛), vì vòng lặp chạy 𝑛lần.

Không gian: 𝑂(1), vì chỉ sử dụng một biến ketQua để lưu kết quả.
*/
#include <iostream>
using namespace std;

long long tinh2MuN_DeQuy(int n) {
    if (n == 0) {
        return 1;
    }
    return 2 * tinh2MuN_DeQuy(n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << tinh2MuN_DeQuy(n) << endl;
    return 0;
}
/*
Khi n=0, hàm trả về giá trị 1.Vì 2^0=1.
Nếu n>0, hàm thực hiện lời gọi đệ quy với n-1 và nhân kết quả trả về với 2.
Độ phức tạp:

Thời gian: 𝑂(𝑛), vì có 𝑛 lời gọi đệ quy.
Không gian: 𝑂(𝑛), do cần 𝑛 khung ngăn xếp để lưu trạng thái của mỗi lời gọi đệ quy.
*/
