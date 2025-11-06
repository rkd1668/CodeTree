#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<char> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    bool check = true;
    while(check) {
        for(int i = 0; i < n; i++) {
            if(a[i] - 'A' > i) {
                char temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                ans++;
                
                break;
                
            }
            if(i == n - 1) check = false;
        }
    }

    cout << ans;
    return 0;
}