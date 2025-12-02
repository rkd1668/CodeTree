#include <iostream>
#include <vector>
using namespace std;

void PrintAnswer(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ChooseNum(int k, int n, int digit, vector<int> &arr) {
    if(digit == n + 1) {
        PrintAnswer(arr);
        return;
    }

    for(int i = 1; i <= k; i++) {
        arr.push_back(i);
        ChooseNum(k, n, digit + 1, arr);
        arr.pop_back();
    }
}

int main() {
    // Please write your code here.
    int k, n;
    cin >> k >> n;
    vector<int> arr;
    ChooseNum(k, n, 1, arr);
    
    return 0;
}