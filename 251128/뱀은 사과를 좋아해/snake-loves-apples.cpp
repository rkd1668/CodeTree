#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dx[4] = {-1, 1, 0, 0}; // U, D, R, L
int dy[4] = {0, 0, 1, -1};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> apple(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        apple[x - 1][y - 1] = 1;
    }

    vector<vector<bool>> snake_exist(n, vector<bool>(n, false));

    deque<pair<int,int>> snake;
    snake.push_back({0, 0});
    snake_exist[0][0] = true;

    int ans = 0;

    for(int i = 0; i < k; i++) {
        char d;
        int p;
        cin >> d >> p;

        int dir;
        if(d == 'U') dir = 0;
        else if(d == 'D') dir = 1;
        else if(d == 'R') dir = 2;
        else dir = 3; // 'L'

        for(int step = 0; step < p; step++) {
            auto head = snake.front();
            int nx = head.first + dx[dir];
            int ny = head.second + dy[dir];

            ans++;

            if(!InRange(nx, ny, n)) {
                cout << ans;
                return 0;
            }

            bool grow = (apple[nx][ny] == 1);
            auto tail = snake.back();

            if(snake_exist[nx][ny]) {
                if(!(nx == tail.first && ny == tail.second && !grow)) {
                    cout << ans;
                    return 0;
                }
            }

            snake.push_front({nx, ny});
            snake_exist[nx][ny] = true;

            if(grow) {
                apple[nx][ny] = 0;
            } else {
                snake_exist[tail.first][tail.second] = false;
                snake.pop_back();
            }
        }
    }

    cout << ans;
    return 0;
}
