#include <iostream>

using namespace std;

string a;

int main() {
    cin >> a;

    // Please write your code here.
    int ans = 0;
    bool notzero = false;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '1') {
            int one = 1;
            one = one << a.length() - 1 - i;
            ans += one;
        }
    }
    
    for(int i = 0; i < a.length(); i++) {
        int temp = 0;
        if(a[i] == '0') {
            a[i] = '1';
            for(int j = 0; j < a.length(); j++) {
                if(a[j] == '1') {
                    int one = 1;
                    one = one << a.length() - 1 - j;
                    temp += one;
                }
            }
            a[i] = '0';
            notzero = true;
        }
    
        if(ans <= temp) {
            ans = temp;
        }
    }

    if(notzero) {
        cout << ans;
    }
    else {
        cout << ans - 1;
    }
    return 0;
}