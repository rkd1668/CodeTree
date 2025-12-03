#include <iostream>
#include <string>
#include <climits>
using namespace std;

int a, b, c, d, e, f;

int ans = INT_MIN;

int CharToInt(char x) {
    if(x == 'a') return a;
    if(x == 'b') return b;
    if(x == 'c') return c;
    if(x == 'd') return d;
    if(x == 'e') return e;
    if(x == 'f') return f;
}

void GetAnswer(string str) {
    int temp_ans = CharToInt(str[0]);
    for(int i = 1; i < str.size(); i += 2) {
        if(str[i] == '+') temp_ans += CharToInt(str[i + 1]);
        if(str[i] == '-') temp_ans -= CharToInt(str[i + 1]);
        if(str[i] == '*') temp_ans *= CharToInt(str[i + 1]);
    }
    if(ans < temp_ans) ans = temp_ans;
}

void Backtracking(int cnt, string str) {
    if(cnt == 6) {
        GetAnswer(str);
        return;
    }

    for(int i = 1; i <= 4; i++) {
        if(cnt == 0) a = i;
        if(cnt == 1) b = i;
        if(cnt == 2) c = i;
        if(cnt == 3) d = i;
        if(cnt == 4) e = i;
        if(cnt == 5) f = i;
        Backtracking(cnt + 1, str);
    }
}


int main() {
    // Please write your code here.
    string str;
    cin >> str;

    Backtracking(0, str);
    cout << ans;
    return 0;
}