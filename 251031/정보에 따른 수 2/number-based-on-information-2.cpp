#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int t, a, b;
    cin >> t >> a >> b;

    vector<int> s, n;

    for(int i = 0; i < t; i++) {
        char c;
        int p;
        cin >> c >> p;
        if(c == 'S') s.push_back(p);
        else n.push_back(p);
    }

    sort(s.begin(), s.end());
    sort(n.begin(), n.end());

    int ans = 0;

    for(int i = a; i <= b; i++) {
        int s_min = INT_MAX, n_min = INT_MAX;
        for(int j = 0; j < s.size(); j++) {
            if(abs(s[j] - i) < s_min) s_min = abs(s[j] - i);
        }
        for(int j = 0; j < n.size(); j++) {
            if(abs(n[j] - i) < n_min) n_min = abs(n[j] - i);
        }
        if(s_min <= n_min) ans++;
    }

    cout << ans;
    return 0;
}