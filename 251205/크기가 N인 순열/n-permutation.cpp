#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ans;
vector<int> visited;

void PrintAnswer() {
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void Choose(int cnt) {
    if(cnt == n) {
        PrintAnswer();
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i] == 1) continue;

        visited[i] = 1;
        ans.push_back(i + 1);
        
        Choose(cnt + 1);

        visited[i] = 0;
        ans.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    visited.resize(n);
    Choose(0);
    
    return 0;
}