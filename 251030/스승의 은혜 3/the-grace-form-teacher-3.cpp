#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n, b;
    cin >> n >> b;

    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int sum = 0;

    for(auto a : v) {
        int temp_sum = sum;
        temp_sum += (a[0] / 2) + a[1];
        if(temp_sum < b) {
            ans++;
            sum += a[0] + a[1];
        }
        else break;
    }

    cout << ans;
    return 0;
}