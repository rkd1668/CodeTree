#include <iostream>
#include <vector>
using namespace std;

int n, max_sum;
vector<vector<int>> grid;
vector<int> selected_c;
vector<int> ans;

void Choose(int r) {
    if(r == n) {
        int sum = 0;
        for(int i = 0; i < ans.size(); i++) {
            sum += ans[i];
        }
        if(max_sum < sum) max_sum = sum;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(selected_c[i] == 1) continue;

        selected_c[i] = 1;
        ans.push_back(grid[r][i]);

        Choose(r + 1);

        selected_c[i] = 0;
        ans.pop_back();
    }
}
int main() {
    // Please write your code here.
    cin >> n;
    grid.resize(n, vector<int>(n));
    selected_c.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Choose(0);
    cout << max_sum;
    return 0;
}