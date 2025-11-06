#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > b[i]) {
            int cnt = a[i] - b[i];
            for(int j = i + 1; j < n; j++) {
                if(a[j] < b[j]) {
                    int cnt2 = b[j] - a[j];
                    if(cnt2 >= cnt) {
                        ans += cnt * (j - i);
                        a[i] -= cnt;
                        a[j] += cnt;
                        break;
                    }
                    else {
                        cnt -= cnt2;
                        ans += cnt2 * (j - i);
                        a[i] -= cnt2;
                        a[j] += cnt2;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}