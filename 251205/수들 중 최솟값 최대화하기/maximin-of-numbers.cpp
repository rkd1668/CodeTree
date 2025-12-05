#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, ans;
vector<vector<int>> grid;
vector<int> selected, value;

void Choose(int r) {
    if(r == n) {
        int min_num = value[0];
        for(int i = 1; i < value.size(); i++) {
            if(min_num > value[i]) min_num = value[i];
        }
        if(ans < min_num) ans = min_num;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(selected[i] == 1) continue;

        selected[i] = 1;
        value.push_back(grid[r][i]);

        Choose(r + 1);

        selected[i] = 0;
        value.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    grid.resize(n, vector<int>(n));
    selected.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Choose(0);
    cout << ans;

    return 0;
}