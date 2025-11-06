#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> first(n), second(n);
    for(int i = 0; i < n; i++) {
        cin >> first[i] >> second[i];
    }

    int ans = 0;
    int cnt = 0;
    //1, 2, 3
    for(int i = 0; i < n; i++) {
        if(first[i] == 1 && second[i] == 2) cnt++;
        if(first[i] == 2 && second[i] == 3) cnt++;
        if(first[i] == 3 && second[i] == 1) cnt++;
        if(cnt > ans) ans = cnt;
    }
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(first[i] == 1 && second[i] == 3) cnt++;
        if(first[i] == 2 && second[i] == 1) cnt++;
        if(first[i] == 3 && second[i] == 2) cnt++;
        if(cnt > ans) ans = cnt;
    }

    cout << ans;
    return 0;
}