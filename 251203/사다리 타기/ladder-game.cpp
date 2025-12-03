#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<pair<int,int>> ladder;   
vector<int> final_result;       
int ans = INT_MAX;

vector<int> simulate(const vector<pair<int,int>>& selected) {
    vector<int> arr(n);
    for(int i = 0; i < n; i++) arr[i] = i + 1;

    for(auto &p : selected) {
        int a = p.second; 
        swap(arr[a - 1], arr[a]);
    }
    return arr;
}


void dfs(int idx, int cnt, vector<pair<int,int>>& cur) {
    if(cnt >= ans) return;

    if(idx == m) {
        vector<int> result = simulate(cur);
        if(result == final_result) {
            ans = cnt;
        }
        return;
    }

    dfs(idx + 1, cnt, cur);

    cur.push_back(ladder[idx]);
    dfs(idx + 1, cnt + 1, cur);
    cur.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    ladder.resize(m);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[i] = {b, a};  
    }

    sort(ladder.begin(), ladder.end());

    final_result = simulate(ladder);

    vector<pair<int,int>> cur;
    dfs(0, 0, cur);

    cout << ans;
    return 0;
}
