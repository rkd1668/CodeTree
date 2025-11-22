#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    
    int ans = 0;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            //if(v[r][c] == 0) continue;
            for(int k = 0; k <= 2 * n; k++) {
                int gold = 0;
                int cost = k * k + (k + 1) * (k + 1);
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if(abs(i - r) + abs(j - c) <= k) {
                            if(v[i][j] == 1) gold++;
                        }
                    }
                }
                if(gold * m >= cost && ans < gold) ans = gold;
            }
        }
    }

    cout << ans;
    return 0;
}