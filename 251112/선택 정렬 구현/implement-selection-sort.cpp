#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &v)
{
    for(int i = 0; i < v.size() - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < v.size(); j++) {
            if(v[min_idx] > v[j]) min_idx = j;
        }
        int temp = v[i];
        v[i] = v[min_idx];
        v[min_idx] = temp;
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

    SelectionSort(v);

    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}