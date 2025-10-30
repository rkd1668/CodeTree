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
        int cnt = 0;
        int number = i;
        vector<int> v;
        while(number > 0) {
            int digit = number % 10;
            v.push_back(digit);
            number /= 10;
        }
        
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++) {
            if(v[i - 1] != v[i]) cnt++;
        }

        if(cnt == 1) ans++;
    }
    
    cout << ans;
    return 0;
}