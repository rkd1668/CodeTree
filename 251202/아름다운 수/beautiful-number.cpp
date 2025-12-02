#include <iostream>
using namespace std;

void BeautifulNumber(int n, int digit, int &ans) {
    if(digit == n) {
        ans++;
        return;
    }
    if(digit > n) return;
    for(int i = 1; i <= 4; i++) {
        BeautifulNumber(n, digit + i, ans);
    }
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int ans = 0;
    BeautifulNumber(n, 0, ans);
    cout << ans;
    return 0;
}