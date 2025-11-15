#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    while(!q.empty()) {
        for(int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}