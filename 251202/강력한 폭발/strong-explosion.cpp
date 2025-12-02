#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1}, dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void GetDestroyedNum(vector<vector<int>> &temp, int n) {
    vector<vector<int>> next_grid(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(temp[i][j] == 1) {
                for(int k = 0; k <= 3; k += 3) {
                    next_grid[i][j] = -1;
                    int next_x = i + dx[k], next_y = j + dy[k];
                    if(InRange(next_x, next_y, n)) next_grid[next_x][next_y] = -1;
                    next_x += dx[k];
                    next_y += dy[k];
                    if(InRange(next_x, next_y, n)) next_grid[next_x][next_y] = -1;
                }
            }
            else if(temp[i][j] == 2) {
                for(int k = 0; k <= 3; k++) {
                    next_grid[i][j] = -1;
                    int next_x = i + dx[k], next_y = j + dy[k];
                    if(InRange(next_x, next_y, n)) next_grid[next_x][next_y] = -1;
                }
            }
            else if(temp[i][j] == 3) {
                for(int k = 4; k <= 7; k++) {
                    next_grid[i][j] = -1;
                    int next_x = i + dx[k], next_y = j + dy[k];
                    if(InRange(next_x, next_y, n)) next_grid[next_x][next_y] = -1;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(next_grid[i][j] == -1) cnt++;
        }
    }
    if(ans < cnt) ans = cnt;
}

void Bomb(int num, int digit, vector<vector<int>> &temp, vector<pair<int, int>> bomb_pos, int n) {
    if(digit == num) {
        GetDestroyedNum(temp, n);
        return;
    }

    for(int i = 1; i <= 3; i++) {
        int x = bomb_pos[digit].first;
        int y = bomb_pos[digit].second;
        temp[x][y] = i;
        Bomb(num, digit + 1, temp, bomb_pos, n);
    }
}


int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<pair<int, int>> bomb_pos;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) bomb_pos.push_back(make_pair(i, j));
        }
    }

    vector<vector<int>> temp(n, vector<int>(n));
    Bomb(bomb_pos.size(), 0, temp, bomb_pos, n);

    cout << ans;
    return 0;
}