#include <iostream>

using namespace std;

int n, m;
int a[100], b[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if((a[i] == a[j] && b[i] == b[j]) || (a[i] == b[j] && b[i] == a[j])) cnt++;
        }
        if(ans < cnt) ans = cnt;
    }
    cout << ans;
    return 0;
}