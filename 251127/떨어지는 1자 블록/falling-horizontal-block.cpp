#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bool check = true;
    int r = 0;
    for(int i = 0; i < n; i++) {
        if(!check) break;
        for(int j = k - 1; j < k - 1 + m; j++) {
            if(i == n - 1) {
                r = i;
                check = false;
                break;
            }
            if(grid[i + 1][j] == 1) {
                r = i;
                check = false;
            }
        }
    }

    for(int j = k - 1; j < k - 1 + m; j++) {
        grid[r][j] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}