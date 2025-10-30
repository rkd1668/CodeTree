#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int n , k;
    cin >> n >> k;

    vector<int> bomb(n);

    for(int i = 0; i < n; i++) {
        cin >> bomb[i];
    }

    int ans = -1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= i + k; j++) {
            if(bomb[i] == bomb[j] && bomb[i] > ans) ans = bomb[i];
        }
    }

    cout << ans;
    return 0;
}