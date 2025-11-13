#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Heapify(vector<int> &v, int n, int i) {
    int largest = i;
    int l = i * 2;
    int r = i * 2 + 1;

    if(l <= n && v[l] > v[largest]) {
        largest = l;
    }
    if(r <= n && v[r] > v[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(v[i], v[largest]);
        Heapify(v, n, largest);
    }
}

void HeapSort(vector<int> &v, int n) {
    for(int i = n / 2; i >= 1; i--) {
        Heapify(v, n, i);
    }

    for(int i = n; i > 1; i--) {
        swap(v[1], v[i]);
        Heapify(v, i - 1, 1);
    }
}
int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> v[i + 1];
    }

    HeapSort(v, n);

    for(int i = 0; i < n; i++) {
        cout << v[i + 1] << " ";
    }
    return 0;
}