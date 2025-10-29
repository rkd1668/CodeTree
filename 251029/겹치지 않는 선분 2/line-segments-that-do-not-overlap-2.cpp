#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> x1(n), x2(n);
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        bool is_cross = true;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(x1[i] < x1[j]) {
                if(x2[i] > x2[j]) {
                    is_cross = true;
                    break;
                }
            }
            else {
                if(x2[i] < x2[j]) {
                    is_cross = true;
                    break;
                }
            }
            is_cross = false;
        }
        if(!is_cross) ans++;
    }

    cout << ans;
    return 0;
}