#include <iostream>
#include <vector>
using namespace std;

int n;
bool isanswer = false;
vector<int> ans;

bool CheckAnswer() {
    int len = ans.size();

    for (int size = 1; size <= len / 2; size++) {
        for (int i = 0; i + 2 * size <= len; i++) {
            bool same = true;
            for (int j = 0; j < size; j++) {
                if (ans[i + j] != ans[i + size + j]) {
                    same = false;
                    break;
                }
            }
            if (same) return false;
        }
    }
    return true;
}

void Choose(int cnt) {
    if (isanswer) return;

    if (cnt == n) {
        isanswer = true;
        return;
    }

    for (int i = 4; i <= 6; i++) {
        ans.push_back(i);

        if (CheckAnswer()) {
            Choose(cnt + 1);
            if (isanswer) return;   
        }

        ans.pop_back();
    }
}

int main() {
    cin >> n;
    Choose(0);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}
