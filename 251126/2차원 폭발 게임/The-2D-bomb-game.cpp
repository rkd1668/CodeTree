#include <iostream>
#include <vector>
using namespace std;


void Fall(vector<vector<int>> &grid, int n) {
    // 각 열별로 아래로 떨어뜨리기 (in-place)
    for (int j = 0; j < n; ++j) {
        int write = n - 1; // 내려갈 위치
        for (int i = n - 1; i >= 0; --i) {
            if (grid[i][j] != 0) {
                grid[write][j] = grid[i][j];
                if (write != i) grid[i][j] = 0;
                --write;
            }
        }
        // 위 쪽 나머지는 0으로 채우기
        while (write >= 0) {
            grid[write][j] = 0;
            --write;
        }
    }
}

// 한 번의 폭발 라운드: 폭발이 있었으면 true 리턴
bool BombOnce(vector<vector<int>> &grid, int n, int m) {
    bool exploded = false;

    for (int j = 0; j < n; ++j) {
        int i = 0;
        while (i < n) {
            if (grid[i][j] == 0) {
                ++i;
                continue;
            }
            int v = grid[i][j];
            int start = i;
            while (i < n && grid[i][j] == v) ++i;
            int len = i - start;
            if (len >= m) {
                exploded = true;
                for (int r = start; r < i; ++r) {
                    grid[r][j] = 0;
                }
            }
        }
    }

    if (exploded) {
        Fall(grid, n);
    }
    return exploded;
}

// 더 이상 터질 게 없을 때까지 BombOnce 반복
void BombAll(vector<vector<int>> &grid, int n, int m) {
    while (BombOnce(grid, n, m)) {
        // 계속 폭발이 이어질 때까지 반복
    }
}

void Rotate(vector<vector<int>> &grid, vector<vector<int>> &tmp, int n) {
    // tmp 재사용 (새로 만들지 않음)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = grid[n - 1 - j][i];
        }
    }
    grid.swap(tmp);
    Fall(grid, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Rotate에서 쓸 임시 배열 하나만 만들어서 계속 재사용
    vector<vector<int>> tmp(n, vector<int>(n));

    for (int t = 0; t < k; ++t) {
        BombAll(grid, n, m);       // 완전히 안정될 때까지 폭발
        Rotate(grid, tmp, n);      // 회전 + 낙하
    }

    BombAll(grid, n, m);           // 마지막에 한 번 더 폭발 처리

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 0) ++ans;
        }
    }
    cout << ans;
    return 0;
}