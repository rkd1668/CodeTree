#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<tuple<int, int, int>> v;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}


int main() {
    // Please write your code here.
    
    cin >> n;
    int grid[500][500] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            v.push_back({grid[i][j], i, j});
        }
    }
    sort(v.begin(), v.end());
    int dp[500][500] = {0};
    int ans = 0;

    for(int i = 0; i < v.size(); i++) {
        int num, x, y;
        tie(num, x, y) = v[i];
        int max_num = 0;
        for(int j = 0; j < 4; j++) {
            int new_x = x + dx[j];
            int new_y = y + dy[j];
            if(InRange(new_x, new_y) && grid[x][y] > grid[new_x][new_y]) {
                int new_num = dp[new_x][new_y];
                max_num = max(new_num, max_num);
            }
        }
        dp[x][y] = max_num + 1;
        if(ans < dp[x][y]) ans = dp[x][y];
    }

    cout << ans;
    return 0;
}