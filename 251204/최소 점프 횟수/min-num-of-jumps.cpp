#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int ans = INT_MAX;
vector<int> arr;

void Move(int cnt, int x) {
    if(x == arr.size() - 1) {
        if(ans > cnt) ans = cnt;
        return;
    }

    if(arr[x] == 0) return;

    for(int i = 1; i <= arr[x]; i++) {
        Move(cnt + 1, x + i);
    }
}
int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    Move(0, 0);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    
    return 0;
}