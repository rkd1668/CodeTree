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
        bool check2 = true;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                char temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                ans++;
                check2 = false;
            }
        }

        if(check2) check = false;
    }
    cout << ans;
    return 0;
}