#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<int> ice(n);
    for(int i = 0; i < n; i++) {
        cin >> ice[i];
    }

    int ans = 0;

    for(int i = 1; i <= 1000; i++) {
        int cnt = 0;
        bool b = false;
        for(int j = 0; j < n; j++) {
            if(ice[j] <= i) {
                b = false;
            }
            else {
                if(b == false) {
                    cnt++;
                    b = true;
                }
            }
        }

        if(ans < cnt) ans = cnt;
    }

    cout << ans;
    return 0;
}