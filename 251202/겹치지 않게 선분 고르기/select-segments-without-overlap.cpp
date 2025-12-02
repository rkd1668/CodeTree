#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back(make_pair(r, l));
    }

    sort(v.begin(), v.end());
    int ans = 1;
    int r = v[0].first, l = v[0].second;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].second > r) {
            ans++;
            r = v[i].first;
            l = v[i].second;
        }
    }
    cout << ans;
    return 0;
}