#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, u, d, ans;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[8][8], visited[8][8];
vector<pair<int, int>> cities;
vector<pair<int, int>> selected_cities;
queue<pair<int, int>> q;
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y, int diff) {
    if(!InRange(x, y)) return false;
    if(diff < u || diff > d) return false;
    if(visited[x][y] == 1) return false;
    return true;
}

void BFS() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    int cnt = 0;
    for(int i = 0; i < selected_cities.size(); i++) {
        int x = selected_cities[i].first;
        int y = selected_cities[i].second;
        q.push({x, y});
        visited[x][y] = 1;
        cnt++;
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int diff = 0;
            if(InRange(new_x, new_y)) {
                diff = abs(grid[x][y] - grid[new_x][new_y]);
            }
            if(CanGo(new_x, new_y, diff)) {
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
                cnt++;
            }
        }
    }

    if(ans < cnt) ans = cnt;
}

void SelectCity(int cnt, int idx) {
    if(cnt == k) {
        BFS();
        return;
    }

    for(int i = idx; i < cities.size(); i++) {
        int x = cities[i].first;
        int y = cities[i].second;
        selected_cities.push_back({x, y});
        SelectCity(cnt + 1, i + 1);
        selected_cities.pop_back();
    }
} 

int main() {
    // Please write your code here.
    cin >> n >> k >> u >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            cities.push_back({i, j});
        }
    }

    SelectCity(0, 0);
    cout << ans;
    return 0;
}