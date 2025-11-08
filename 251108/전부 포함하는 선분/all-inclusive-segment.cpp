#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> x1(n), x2(n);
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        int min_x1 = INT_MAX;
        int max_x2 = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(x1[j] < min_x1) min_x1 = x1[j];
            if(x2[j] > max_x2) max_x2 = x2[j];
        }
        if(ans > max_x2 - min_x1) {
            ans = max_x2 - min_x1;
        }
    }
    
    cout << ans;
    return 0; 
}