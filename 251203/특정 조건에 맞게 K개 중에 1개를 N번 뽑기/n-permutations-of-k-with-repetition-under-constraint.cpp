#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> ans;

void PrintAnswer() {
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void ChooseNum(int cnt) {
    if(cnt == n) {
        PrintAnswer();
        return;
    }

    for(int i = 1; i <= k; i++) {
        if(cnt >= 2 && ans[cnt - 2] == i && ans[cnt - 1] == i) continue;
        ans.push_back(i);
        ChooseNum(cnt + 1);
        ans.pop_back();
    }
}
int main() {
    // Please write your code here.
    cin >> k >> n;
    ChooseNum(0);
    return 0;
}