#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<double> numbers(5);
    for(int i = 0; i < 5; i++){
        cin >> numbers[i];
    }
    double maxNumber = *max_element(numbers.begin(), numbers.end());
    double minNumber = *min_element(numbers.begin(), numbers.end());
    double sum = maxNumber + minNumber;
    cout << sum;
    return 0;
}
