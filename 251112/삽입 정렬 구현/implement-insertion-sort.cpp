#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &v) {
    for(int i = 1; i < v.size(); i++) {
        int key = v[i];
        for(int j = i - 1; j >= -1; j--) {
            if(v[j] > key && j >= 0) {
                v[j + 1] = v[j];
            }
            else {
                v[j + 1] = key;
                break;
            }
        }
    }
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    InsertionSort(v);

    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}