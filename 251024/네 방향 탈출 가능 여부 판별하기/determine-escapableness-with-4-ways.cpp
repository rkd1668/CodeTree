#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int a[100][100];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool visited[100][100];
bool success;

queue<pair<int, int>> q;

void Push(int x, int y) {
    visited[x][y] = true;
    q.push(make_pair(x, y));
    
}

bool InRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool CanGo(int x, int y) {
    if(!InRange) return false;
    if(visited[x][y] || a[x][y] == 0) return false;
    return true;
}

void BFS() {
    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(CanGo(next_x, next_y)) {
                if(next_x == n - 1 && next_y == m - 1) success = true;
                Push(next_x, next_y);
            }
        }
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    Push(0, 0);
    BFS();
    if(success) cout << 1;
    else cout << 0;
    return 0;
}
