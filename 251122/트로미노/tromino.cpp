#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + 1 < n && j + 1 < m) {
                int sum = v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1];
                if(ans < sum - v[i][j]) ans = sum - v[i][j];
                if(ans < sum - v[i][j + 1]) ans = sum - v[i][j + 1];
                if(ans < sum - v[i + 1][j]) ans = sum - v[i + 1][j];
                if(ans < sum - v[i + 1][j + 1]) ans = sum - v[i + 1][j + 1];
            }
            if(i + 2 < n) {
                int sum = v[i][j] + v[i + 1][j] + v[i + 2][j];
                if(ans < sum) ans = sum;
            }
            if(j + 2 < m) {
                int sum = v[i][j] + v[i][j + 1] + v[i][j + 2];
                if(ans < sum) ans = sum;
            }
        }
    }

    cout << ans;
    return 0;
}