#include <iostream>

using namespace std;

int n, m;
int from[10000], to[10000];
int arr[1001][1001];
int visited[1001] = {false};
int ans = 0;

void DFS(int vertex) {
    for(int curr_v = 2; curr_v <= n; curr_v++) {
        if(arr[vertex][curr_v] && !visited[curr_v]) {
            ans++;
            visited[curr_v] = true;
            DFS(curr_v);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // Please write your code here.
    
    for(int i = 0; i < m; i++) {
        arr[from[i]][to[i]] = 1;
        arr[to[i]][from[i]] = 1;
    }

    DFS(1);
    cout << ans;
    return 0;
}
