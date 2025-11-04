#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    string str;
    cin >> n >> str;

    int ans = 0;

    for(int i = 0; i < str.size(); i++) {
        for(int j = i + 1; j < str.size(); j++) {
            string temp_str = str;
            if(temp_str[i] == '1' || temp_str[j] == '1') continue;
            temp_str[i] = '1';
            temp_str[j] = '1';

            int min_dist = INT_MAX, start_idx = -1;
            for(int k = 0; k < str.size(); k++) {
                if(start_idx == -1 && temp_str[k] == '1') start_idx = k;
                else if(start_idx != -1 && temp_str[k] == '1') {
                    int dist = k - start_idx;
                    start_idx = k;
                    if(dist < min_dist) min_dist = dist;
                } 
            }
            if(ans < min_dist) {
                ans = min_dist;
            }
        }
    }

    cout << ans;
    return 0;
}