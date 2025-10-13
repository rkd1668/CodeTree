#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a, b, c;

int main() {
    cin >> N;
    cin >> a >> b >> c;

    // Please write your code here.
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(abs(i - a) <= 2 || abs(j - b) <= 2 || abs(k - c) <= 2) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}