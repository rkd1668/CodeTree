#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int> &v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        if(v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void QuickSort(vector<int> &v, int low, int high) {
    if(low < high) {
        int pos = Partition(v, low, high);

        QuickSort(v, low, pos - 1);
        QuickSort(v, pos + 1, high);
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

    QuickSort(v, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}