#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int village_cnt = 0;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
vector<vector<int>> grid, visited;
vector<int> ans;
bool InRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void DFS(int r, int c, int cnt) {
    if(cnt == 0 && visited[r][c] != 0) return;
    if(cnt == 0) {
        ans.push_back(0);
    }

    visited[r][c] = cnt + 1;
    ans[ans.size() - 1]++;
    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[i], next_c = c + dc[i];
        if(InRange(next_r, next_c) && grid[next_r][next_c] == 1 && visited[next_r][next_c] == 0) {
            DFS(next_r, next_c,cnt + 1);
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) DFS(i, j, 0); 
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}