#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = INT_MAX;
    for(int i = 2; i <= 100; i += 2) {
        for(int j = 2; j <= 100; j += 2) {
            int cnt[4] = {};
            for(int k = 0; k < n; k++) {
                if(x[k] < i && y[k] < j) cnt[0]++;
                else if(x[k] < i && y[k] > j) cnt[1]++;
                else if(x[k] > i && y[k] < j) cnt[2]++;
                else cnt[3]++;
            }
            int cnt_max = 0;
            for(int k = 0; k < 4; k++) {
                if(cnt_max < cnt[k]) cnt_max = cnt[k];
            }

            if(ans > cnt_max) ans = cnt_max;
        }
    }
    
    cout << ans;
    return 0;
}