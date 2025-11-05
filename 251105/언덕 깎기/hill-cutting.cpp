#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }    

    sort(h.begin(), h.end());

    int start = h[0];
    int end = h[n - 1];
    int ans = INT_MAX;

    if(end - start <= 17) ans = 0;
    else {
        for(int i = 0; i <= end - 17 - start; i++) {
            int cost = 0;
            int j = end - 17 - start - i;
            cost = i * i + j * j;
            if(ans > cost) ans = cost;
        }
    }

    cout << ans;
    return 0;
}