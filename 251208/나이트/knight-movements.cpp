#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n, r1, c1, r2, c2;
int ans = INT_MAX;

int step[100][100], visited[100][100];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void BFS() {
    q.push({r1, c1});
    visited[r1][c1] = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int new_r = r + dx[i];
            int new_c = c + dy[i];

            if(InRange(new_r, new_c) && visited[new_r][new_c] == 0) {
                visited[new_r][new_c] = 1;
                q.push({new_r, new_c});
                step[new_r][new_c] = step[r][c] + 1;

                if(visited[r2][c2] == 1) {
                    ans = step[r2][c2];
                    return;
                }
            }
        }

        
    }
}


int main() {
    // Please write your code here.
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    BFS();
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}