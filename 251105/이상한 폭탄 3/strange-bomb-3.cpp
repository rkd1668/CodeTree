#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;
    vector<int> bomb(n);
    for(int i = 0; i < n; i++) {
        cin >> bomb[i];
    }

    vector<int> explosion(1000001);

    for(int i = 0; i < n - 1; i++) {
        bool check = false;
        if(bomb[i] == 0) continue;
        for(int j = 1; j <= k; j++) {
            if(i + j >= n) break;
            if(bomb[i] == bomb[i + j]) {
                check = true;
                explosion[bomb[i]]++;
                bomb[i + j] = 0;
            }
        }
        if(check) {
            explosion[bomb[i]]++;
            bomb[i] = 0;
        }
    }

    int ans = 0;
    int max_exp = 0;
    for(int i = 0; i < explosion.size(); i++) {
        if(max_exp <= explosion[i]) {
            max_exp = explosion[i];
            ans = i;
        }
    }

    cout << ans;
    return 0;
}