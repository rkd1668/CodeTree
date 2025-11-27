#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    x--;
    y--;

    int ans = -1;
    int time = 0;
    int dir = 0;
    int cnt = 0;

    while(InRange(x, y, n)) {
        int next_x = x + dx[dir];
        int next_y = y + dy[dir];
        if(time > n * n  || cnt > 4) {
            time = 0;
            break;
        }
        if(InRange(next_x, next_y, n) && grid[next_x][next_y] == '#') {
            dir = (dir + 1) % 4;
            cnt++;
            continue;
        }
        if(!InRange(next_x, next_y, n)) {
            time++;
            break;
        }
        if(InRange(next_x, next_y, n) && grid[next_x + dx[(dir + 3) % 4]][next_y + dy[(dir + 3) % 4]] == '#') {
            time++;
            x = next_x;
            y = next_y;
            cnt = 0;
            continue;
        }
        if(InRange(next_x, next_y, n) && grid[next_x + dx[(dir + 3) % 4]][next_y + dy[(dir + 3) % 4]] == '.') {
            time += 2;
            x = next_x + dx[(dir + 3) % 4];
            y = next_y + dy[(dir + 3) % 4];
            dir = (dir + 3) % 4;
            cnt = 0;
            continue;
        }
        
    }

    if(time != 0) {
        ans = time;
        cout << ans;
    }
    else {
        cout << ans;
    }
    return 0;
}