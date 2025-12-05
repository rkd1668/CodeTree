#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int ans = INT_MAX;
vector<vector<int>> graph;
vector<int> selected_num;
vector<int> cost;
void Choose(int r, int cnt) {
    if(cnt == n - 1) {
        if(graph[r][0] == 0) return;
        cost.push_back(graph[r][0]);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += cost[i];
        }
        if(ans > sum) ans = sum;
        cost.pop_back();
        return;
    }

    for(int i = 1; i < n; i++) {
        if(selected_num[i] == 1 || graph[r][i] == 0) continue;

        selected_num[i] = 1;
        cost.push_back(graph[r][i]);
        Choose(i, cnt + 1);
        selected_num[i] = 0;
        cost.pop_back();
        
    }
}
int main() {
    // Please write your code here.
    cin >> n;
    graph.resize(n, vector<int>(n));
    selected_num.resize(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    Choose(0, 0);
    cout << ans;
    return 0;
}