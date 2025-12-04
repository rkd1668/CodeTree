#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int ans = INT_MAX;

vector<pair<int, int>> grid;
vector<pair<int, int>> selected;

void GetAnswer() {
    int dist = 0;
    for(int i = 0; i < m - 1; i++) {
        for(int j = i + 1; j < m; j++) {
            int temp_dist = 0;
            int x1, x2, y1, y2;
            x1 = selected[i].first;
            y1 = selected[i].second;
            x2 = selected[j].first;
            y2 = selected[j].second;
            temp_dist = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
            if(temp_dist > dist) dist = temp_dist;
        }
    }
    if(ans > dist) ans = dist;
}
void Choose(int idx, int cnt) {
    if(cnt == m) {
        GetAnswer();
        return;
    }

    for(int i = idx; i < n; i++) {
        selected.push_back(grid[i]);
        Choose(i + 1, cnt + 1);
        selected.pop_back();
    }
}
int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid.push_back(make_pair(x, y));
    }

    Choose(0, 0);
    cout << ans;
    return 0;
}