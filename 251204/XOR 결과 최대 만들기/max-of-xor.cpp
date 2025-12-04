#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int ans = INT_MIN;
vector<int> arr;
vector<int> selected;
void DoXOR() {
    int x = 0;
    for(int i = 0; i < selected.size(); i++) {
        x = x ^ selected[i];
    }
    if(ans < x) ans = x;
}
void Choose(int idx, int cnt) {
    if(cnt == m) {
        DoXOR();
        return;
    }

    for(int i = idx + 1; i < n; i++) {
        selected.push_back(arr[i]);
        Choose(i + 1, cnt + 1);
        selected.pop_back();
    }
}
int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    Choose(-1, 0);
    cout << ans;
    return 0;
}