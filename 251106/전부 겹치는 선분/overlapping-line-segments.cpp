#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> x1(n), x2(n);
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());

    if(x1[n - 1] > x2[0]) cout << "No";
    else cout << "Yes";
    return 0;
}