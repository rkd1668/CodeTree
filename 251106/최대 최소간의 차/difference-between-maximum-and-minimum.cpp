#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = INT_MAX;
    int dist = v[n - 1] - v[0];

    for(int i = v[0]; i <= v[n - 1]; i++) {
        for(int j = v[n - 1]; j >= i; j--) {
            if(j - i > k) continue;
            int cost = 0;
            for(int k = 0; k < n; k++) {
                if(v[k] < i) {
                    cost += i - v[k];
                }
                else if(v[k] > j) {
                    cost += v[k] - j;
                }
            }
            if(cost < ans) ans = cost;
        }
    }
    cout << ans;
    return 0;

}