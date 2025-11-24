#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, t;
    cin >> n >> t;
    vector<int> v1(n), v2(n), v3(n);

    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v3[i];
    }

    for(int i = 0; i < t; i++) {
        int tmp1 = v1[n - 1], tmp2 = v2[n - 1], tmp3 = v3[n - 1];
        for(int i = n - 1; i >= 1; i--) {
            v1[i] = v1[i - 1];
            v2[i] = v2[i - 1];
            v3[i] = v3[i - 1];
        }
        v1[0] = tmp3;
        v2[0] = tmp1;
        v3[0] = tmp2;
    }

    for(int i = 0; i < n; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << v3[i] << " ";
    }
    return 0;
}