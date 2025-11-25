#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int s1, e1, s2, e2;
    cin >> s1 >> e1 >> s2 >> e2;

    vector<int> temp;
    for(int i = 0; i < arr.size(); i++) {
        if(i < s1 - 1 || i >= e1) {
            temp.push_back(arr[i]);
        }
    }
    arr = temp;
    temp.clear();
    for(int i = 0; i < arr.size(); i++) {
        if(i < s2 - 1 || i >= e2) {
            temp.push_back(arr[i]);
        }
    }
    arr = temp;
    cout << arr.size() << endl;
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    return 0;
}