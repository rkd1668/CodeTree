#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max_value = v[0];
    for(int i = 1; i < n; i++) {
        if(max_value < v[i]) max_value = v[i];
    }

    int ans = 0;
    for(int i = max_value; i < 10000; i++) {
        int cnt = 0;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(sum + v[j] > i) {
                cnt++;
                sum = v[j];
            }
            else {
                sum += v[j];
            }
        }
        if(cnt <= m - 1) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}