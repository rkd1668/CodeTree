#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

int n, sr, sc, er, ec;
int ans = INT_MAX;
vector<vector<char>> grid;
vector<tuple<char, int, int>> numbers;
vector<tuple<char, int, int>> selected;

void GetDist() {
    int dist = 0;
    int cr = sr, cc = sc;
    for(int i = 0; i < selected.size(); i++) {
        char num;
        int r, c;
        tie(num, r, c) = selected[i];
        dist += abs(cr - r) + abs(cc - c);
        cr = r;
        cc = c;
    }
    dist += abs(cr - er) + abs(cc - ec);
    if(ans > dist) ans = dist;
}
void Choose(int idx, int cnt) {
    if(cnt == 3) {
        GetDist();
        return;
    }

    for(int i = idx; i < numbers.size(); i++) {
        selected.push_back(numbers[i]);
        Choose(i + 1, cnt + 1);
        selected.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    grid.resize(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] >= 49 && grid[i][j] <= 57) {
                numbers.push_back(make_tuple(grid[i][j], i, j));
            }
            if(grid[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if(grid[i][j] == 'E') {
                er = i;
                ec = j;
            }
        }
    }

    sort(numbers.begin(), numbers.end());

    Choose(0, 0);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
  
    return 0;
}