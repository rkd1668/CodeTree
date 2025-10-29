#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n, b;
    cin >> n >> b;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());

    int ans = 0;
    int p_sum = 0;

    for(int i = 0; i < n; i++) {
        int sum = p_sum;
        sum += (p[i] / 2);
        if(sum <= b) {
            ans++;
            p_sum += p[i];
        }
        else break;
    }

    cout << ans;
    return 0;
}