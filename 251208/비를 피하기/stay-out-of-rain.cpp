#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, h, m;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[100][100], visited[100][100], answer[100][100];
queue<pair<int, int>> q;
vector<pair<int, int>> h_pos;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(grid[x][y] == 1 || visited[x][y] == 1) return false;
    return true; 
}

void BFS() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    int temp[100][100] = {0, };
    int start_x = q.front().first;
    int start_y = q.front().second;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(CanGo(new_x, new_y)) {
                visited[new_x][new_y] = 1;
                temp[new_x][new_y] = temp[x][y] + 1;
                q.push({new_x, new_y});

                if(grid[new_x][new_y] == 3) {
                    answer[start_x][start_y] = temp[new_x][new_y];
                    return;
                }
            }
        }
    }

    answer[start_x][start_y] = -1;
}
int main() {
    // Please write your code here.
    cin >> n >> h >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) {
                h_pos.push_back({i, j});
            }
        }
    }
    
    for(int i = 0; i < h; i++) {
        while(!q.empty()) {
            q.pop();
        }
        q.push(h_pos[i]);
        BFS();
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}