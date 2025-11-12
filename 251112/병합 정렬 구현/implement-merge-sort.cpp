#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &v, int low, int mid, int high) {
    int i = low, j = mid + 1;
    int k = low;
    vector<int> merged_arr;

    while(i <= mid && j <= high) {
        if(v[i] <= v[j]) {
            merged_arr.push_back(v[i]);
            i++;
        }
        else {
            merged_arr.push_back(v[j]);
            j++;
        }
    }

    while(i <= mid) {
        merged_arr.push_back(v[i]);
        i++;
    }

    while(j <= high) {
        merged_arr.push_back(v[j]);
        j++;
    }

    v = merged_arr;
}

void MergeSort(vector<int> &v, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSort(v, low, mid);
        MergeSort(v, mid + 1, high);
        Merge(v, low, mid, high);
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

    MergeSort(v, 0, v.size() - 1);

    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    } 
    return 0;
}