#include <iostream>
#include <queue>
using namespace std;

int n, k, cnt;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[100][100], visited[100][100];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y, int num) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] == 1) return false;
    if(grid[x][y] >= num) return false;
    return true;
}

void BFS(int &r, int &c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    int next_num = 0;
    int next_r = 101, next_c = 101;
    
    visited[r][c] = 1;
    q.push({r, c});

    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;
        for(int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(CanGo(next_x, next_y, grid[r][c])) {
                visited[next_x][next_y] = 1;
                q.push(make_pair(next_x, next_y));
                if(next_num < grid[next_x][next_y]) {
                    next_num = grid[next_x][next_y];
                    next_r = next_x;
                    next_c = next_y;
                }
                else if(next_num == grid[next_x][next_y]) {
                    next_num = grid[next_x][next_y];
                    if(next_r > next_x) {
                        next_r = next_x;
                        next_c = next_y;
                    }
                    else if(next_r == next_x && next_c > next_y) {
                        next_c = next_y;
                    }
                }
            }
        }   
    }

    if(next_r == 101 || next_c == 101) return;
    r = next_r;
    c = next_c;
}

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    r--;
    c--;
    while(k--) {
        BFS(r, c);
        
    }

    cout << r + 1 << " " << c + 1;
    return 0;
}