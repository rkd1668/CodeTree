#include <iostream>
#include <vector>
using namespace std;

bool InRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    // Please write your code here.
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--;
    c--;
    
    int dist = 1;
    vector<vector<int>> grid(n, vector<int>(n));
    grid[r][c] = 1;
    for(int t = 1; t <= m; t++) {
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    v.push_back(make_pair(i, j));
                }
            }
        }
        
        for(int i = 0; i < v.size(); i++) {
            int x = v[i].first, y = v[i].second;
            if(InRange(x - dist, y, n)) grid[x - dist][y] = 1;
            if(InRange(x + dist, y, n)) grid[x + dist][y] = 1;
            if(InRange(x, y - dist, n)) grid[x][y - dist] = 1;
            if(InRange(x, y + dist, n)) grid[x][y + dist] = 1;
        }
        dist *= 2;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) ans++;
        }
    }

    cout << ans;
    return 0;
}