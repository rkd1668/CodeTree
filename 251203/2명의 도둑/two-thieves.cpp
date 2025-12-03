#include <iostream>
#include <vector>
using namespace std;

int n, m, C;
vector<vector<int>> grid;
int ans = 0;

void Backtracking(vector<int> &thief1, vector<int> &thief2,
                  int idx, int sum1, int sum2, int val1, int val2) {
    int totalLen = thief1.size() + thief2.size();

    if (sum1 > C || sum2 > C) return;

    if (idx == totalLen) {
        int cur = val1 + val2;
        if (cur > ans) ans = cur;
        return;
    }

    if (idx < (int)thief1.size()) {
        int v = thief1[idx];

        Backtracking(thief1, thief2,
                     idx + 1,
                     sum1 + v, sum2,
                     val1 + v * v, val2);

        Backtracking(thief1, thief2,
                     idx + 1,
                     sum1, sum2,
                     val1, val2);
    }
    else {
        int j = idx - (int)thief1.size();
        int v = thief2[j];

        Backtracking(thief1, thief2,
                     idx + 1,
                     sum1, sum2 + v,
                     val1, val2 + v * v);

        Backtracking(thief1, thief2,
                     idx + 1,
                     sum1, sum2,
                     val1, val2);
    }
}

int main() {
    cin >> n >> m >> C;
    grid.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 <= n - m; j1++) {

            vector<int> thief1(m);
            for (int k = 0; k < m; k++) {
                thief1[k] = grid[i1][j1 + k];
            }

            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = 0; j2 <= n - m; j2++) {

                    if (i1 == i2) {
                        if (j2 <= j1) continue; 

                        int left1 = j1;
                        int right1 = j1 + m - 1;
                        int left2 = j2;
                        int right2 = j2 + m - 1;

                        bool overlap = !(right1 < left2 || right2 < left1);
                        if (overlap) continue;
                    }

                    vector<int> thief2(m);
                    for (int k = 0; k < m; k++) {
                        thief2[k] = grid[i2][j2 + k];
                    }
                    Backtracking(thief1, thief2, 0, 0, 0, 0, 0);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
