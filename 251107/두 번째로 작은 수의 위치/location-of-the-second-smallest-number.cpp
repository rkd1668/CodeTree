#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int min_num = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(min_num > v[i]) min_num = v[i];
    }

    int ans = -1;
    int second_num = INT_MAX; 
    for(int i = 0; i < n; i++) {
        if(second_num > v[i] && v[i] != min_num) {
            second_num = v[i];
            ans = i + 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(second_num == v[i]) cnt++;
    }

    if(cnt == 1) cout << ans;
    else cout << -1;
    return 0;
}