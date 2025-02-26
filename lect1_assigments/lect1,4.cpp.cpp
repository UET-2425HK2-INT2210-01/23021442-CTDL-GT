#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < n; i++){
        cout << numbers[i];
        if (i < n - 1)
            cout << " ";
    }
    return 0;
}
