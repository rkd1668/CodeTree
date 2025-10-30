#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int x, y;
    cin >> x >> y;

    int ans = 0;
    for(int i = x; i <= y; i++) {
        int cnt1 = 0, cnt2 = 0;
        int number = i;
        vector<int> v;
        while(number > 0) {
            int digit = number % 10;
            v.push_back(digit);
            number /= 10;
        }
        
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            int min = v[0];
            int max = v[v.size() - 1];
            if(min != v[i]) cnt1++;
            if(max != v[i]) cnt2++;
        }

        if(cnt1 == 1 || cnt2 == 1) ans++;
    }
    
    cout << ans;
    return 0;
}