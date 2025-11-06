#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> x1(n), x2(n);
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    bool check = false;
    for(int i = 0; i < n; i++) {
        int max_x1 = 0, min_x2 = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(max_x1 < x1[j]) max_x1 = x1[j];
            if(min_x2 > x2[j]) min_x2 = x2[j];
        }

        if(max_x1 <= min_x2) {
            check = true;
            break;
        }
    }
    if(check) cout << "Yes";
    else cout << "No";
    return 0;
}