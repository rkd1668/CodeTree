#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
    return (v1[0] + v1[1]) < (v2[0] + v2[1]);
}
int main() {
    // Please write your code here.
    int n, b;
    cin >> n >> b;

    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    int ans = 0;


    for(int i = 0; i < n; i++) {
        vector<vector<int>> temp_v = v;
        temp_v[i][0] /= 2;

        sort(temp_v.begin(), temp_v.end(), cmp);

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += temp_v[i][0] + temp_v[i][1];
            if(sum > b && ans < i) {
                ans = i;
                break;
            }
        }
    }
    
    cout << ans;
    return 0;
}