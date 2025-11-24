#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = -1;

    for(int x1 = 0; x1 < n; x1++) {
        for(int y1 = 0; y1 < m; y1++) {
            for(int x2 = x1; x2 < n; x2++) {
                for(int y2 = y1; y2 < m; y2++) {
                    bool positive = true;
                    for(int i = x1; i <= x2; i++) {
                        for(int j = y1; j <= y2; j++) {
                            if(grid[i][j] <= 0) positive = false;
                        }
                    }
                    if(positive) {
                        int size = (x2 - x1 + 1) * (y2 - y1 + 1);
                        if(ans < size) ans = size;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}