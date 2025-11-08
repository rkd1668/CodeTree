#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n * 2);
    for(int i = 0; i < n * 2; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

   
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(v[n + i] - v[i] < ans) ans = v[n + i] - v[i];
    }

    cout << ans;
    return 0;
}