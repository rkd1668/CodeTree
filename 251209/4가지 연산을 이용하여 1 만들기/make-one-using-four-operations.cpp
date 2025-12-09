#include <iostream>
#include <queue>
using namespace std;

int n, ans;
int visited[2000000];
queue<int> q;

int Calculate(int num, int i) {
    if(i == 0) {
        return num - 1;
    }
    else if(i == 1) {
        return num + 1;
    }
    else if(i == 2 && i % 2 == 0) {
        return num / 2;
    }
    else if(i == 3 && i % 3 == 0) {
        return num / 3;
    }
}

void BFS() {
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(i == 2 && num % 2 != 0) continue;
            if(i == 3 && num % 3 != 0) continue;
            int new_num = Calculate(num, i);
            if(visited[new_num] != 0) continue;
            q.push(new_num);
            visited[new_num] = visited[num] + 1;
            if(visited[1] != 0) {
                ans = visited[1] - 1;
                return;
            }
        }
        
    }

}

int main() {
    // Please write your code here.
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    q.push(n);
    visited[n] = 1;
    BFS();

    cout << ans;
    return 0;
}