#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n) {
    while (n != 0){
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}
int main(){
    int m, n;
    cin >> m >> n;
    cout << gcd(m, n);
    return 0;
}
