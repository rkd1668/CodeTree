#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n);
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] % 2 == 0) even++;
        else odd++;
    }

    int ans = 0;
    while(odd - even >= 3) {
        odd -= 2;
        even++;
    }
    
    if(even == odd) ans = even * 2;
    else if(even > odd) {
        ans = odd * 2 + 1;
    }
    else {
        if(odd - even == 1) {
            ans = even * 2 - 1;
        }
        else if(odd - even == 2) {
            ans = even * 2 + 1;
        }
    }

    cout << ans;
    return 0;
}