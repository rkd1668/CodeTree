#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n ;i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt1 = 1, cnt2 = 1;
        for(int j = 1; j < n; j++) {
            if(v[i][j] == v[i][j - 1]) cnt1++;
            else cnt1 = 1;
            if(cnt1 >= m) {
                ans++;
                break;
            }
        }

        for(int j = 1; j < n; j++) {
            if(v[j][i] == v[j - 1][i]) cnt2++;
            else cnt2 = 1;
            if(cnt2 >= m) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}