#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n , m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int index = i;
        for(int j = 0; j < m; j++) {
            sum += v[index];
            index = v[index] - 1;
        }
        if(ans < sum) ans = sum;
    }

    cout << ans;
    return 0;
}