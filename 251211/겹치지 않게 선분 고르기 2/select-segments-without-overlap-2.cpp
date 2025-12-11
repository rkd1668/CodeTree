#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back({x2, x1});
    }

    sort(v.begin(), v.end());

    int ans = 1;
    int end = v[0].first;
    //int start = v[0].second;
    
    for(int i = 0; i < v.size(); i++) {
        if(end < v[i].second) {
            end = v[i].first;
            ans++;
            continue;
        }
    }

    cout << ans;
    return 0;
}