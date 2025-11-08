#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    
    for(int i = 0; i < n - 1; i++) {
        if(v[i] > v[i + 1]) {
            ans = i + 1;
        }
    }

    cout << ans;

    return 0;
}