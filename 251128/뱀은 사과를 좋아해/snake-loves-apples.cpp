#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    // Please wrie your code here.
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        grid[x - 1][y - 1] = 1;
    }
    vector<pair<int, int>> snake;
    snake.push_back(make_pair(0, 0));

    int ans = 0;
    for(int i = 0; i < k; i++) {
        char d;
        int p;
        int dir = 0;
        cin >> d >> p;
        if(d == 'U') dir = 0;
        else if(d == 'D') dir = 1;
        else if(d == 'R') dir = 2;
        else dir = 3;

        bool check = true;
        for(int j = 0; j < p; j++) {
            int next_x = snake[0].first + dx[dir];
            int next_y = snake[0].second + dy[dir];
            int tail_x = snake[snake.size() - 1].first;
            int tail_y = snake[snake.size() - 1].second;

            ans++;
            if(!InRange(next_x, next_y, n)) {
                check = false;
                break;
            }

            for(int l = snake.size() - 1; l > 0; l--) {
                snake[l] = make_pair(snake[l - 1].first, snake[l - 1].second);
            }
            snake[0] = make_pair(next_x, next_y);

            for(int l = 1; l < snake.size(); l++) {
                if(snake[0] == snake[l]) {
                    check = false;
                    break;
                }
            }
            if(grid[snake[0].first][snake[0].second] == 1) {
                snake.push_back(make_pair(tail_x, tail_y));
                grid[snake[0].first][snake[0].second] = 0;
            }
        }

        if(!check) break;
    }

    cout << ans;
    return 0;
}