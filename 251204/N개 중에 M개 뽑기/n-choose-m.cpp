#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;
vector<int> selected;

void PrintAnswer() {
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void Choose(int num,int cnt) {
    if(cnt == m) {
        PrintAnswer();
        return;
    }

    for(int i = num + 1; i <= n; i++) {
        ans.push_back(i);
        Choose(i, cnt + 1);
        ans.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    selected.resize(n + 1);
    Choose(0, 0);

    return 0;
}