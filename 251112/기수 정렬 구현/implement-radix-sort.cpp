#include <iostream>
#include <vector>
using namespace std;

int GetDigit(int num, int pos) {
    while(pos > 0) {
        num /= 10;
        pos--;
    }
    int digit = num % 10;
    return digit;
}
void RadixSort(vector<int> &v, int k) {
    for(int pos = 0; pos < k; pos++) {
        vector<vector<int>> arr_new(10);
        for(int i = 0; i < v.size(); i++) {
            int digit = GetDigit(v[i], pos);
            arr_new[digit].push_back(v[i]);
        }

        vector<int> store_v;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < arr_new[i].size(); j++) {
                store_v.push_back(arr_new[i][j]);
            }
        }

        v = store_v;
    }
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> arr(n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        int num;
        int digit = 0;
        num = arr[i];
        while(num > 0) {
            num /= 10;
            digit++;
        }
        if(k < digit) k = digit;
    }

    RadixSort(arr, k);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}