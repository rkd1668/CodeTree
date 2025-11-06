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
    for(int i = v[0]; i <= v[n - 1]; i++) {
        int cost = 0;
        if(v[n - 1] - i <= k) {
            for(int j = 0; j < n; j++) {
                if(v[j] < i) {
                    cost += i - v[j];
                }
            }
        }
        else {
            int max_num = i + k;
            for(int j = 0; j < n; j++) {
                if(v[j] < i) {
                    cost += i - v[j];
                }
                else if(v[j] > max_num) {
                    cost += v[j] - max_num;
                }
            }
        }

        if(ans > cost) ans = cost;
    }

    cout << ans;
    return 0;

}