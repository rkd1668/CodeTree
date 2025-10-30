#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    for(int k = 0; k <= 100; k++) {
        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(v[j] - k == k - v[i]) cnt++;
            }
        }
        if(ans < cnt) ans = cnt;
    }

    cout << ans;
    return 0;
}