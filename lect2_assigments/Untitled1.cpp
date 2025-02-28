#include <bits/stdc++.h>
using namespace std;
int countPairs(int n, const vector<int>& A) {
    unordered_map<int, int> freq;
    int count = 0;
    for(int num : A) {
        count += freq[num];
        freq[num]++;
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << countPairs(n, A);
    return 0;
}
