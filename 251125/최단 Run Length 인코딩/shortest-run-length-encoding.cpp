#include <iostream>
#include <string>
#include <climits>

using namespace std;

void Shift(string &a) {
    char temp = a[a.size() - 1];
    for(int i = a.size() - 1; i >= 1; i--) {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}

int GetRunLength(string a) {
    int cnt = 0;
    bool check = true;
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] != a[i + 1]) {
            cnt += 2;
            check = false;
        }
    }
    cnt += 2;
    if(check) cnt++;
    return cnt;
}

int main() {
    // Please write your code here.
    string a;
    cin >> a;
    
    int ans = GetRunLength(a);
    
    for(int i = 0; i < a.size(); i++) {
        Shift(a);
        if(ans > GetRunLength(a)) ans = GetRunLength(a);
    }
    
    cout << ans;
    return 0;
}