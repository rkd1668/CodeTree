#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    
    for(int i = 100; i >= 0; i--) {
        int cnt = 0;
        int l_cnt = 0;
        for(int j = 0; j < n; j++) {
            if(v[j] >= i) cnt++;
            else if(v[j] + 1 == i && l_cnt < l) {
                l_cnt++;
                cnt++;
            } 
        }
        if(cnt >= i) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}