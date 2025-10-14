#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

bool Compare(int i, int j, int k) {
    if(min(abs(i - a1),N - abs(i - a1)) <= 2 && min(abs(j - b1),N - abs(j - b1)) <= 2 && min(abs(k - c1),N - abs(k - c1)) <= 2)
    {
        return true;
    }
    if(min(abs(i - a2),N - abs(i - a2)) <= 2 && min(abs(j - b2),N - abs(j - b2)) <= 2 && min(abs(k - c2),N - abs(k - c2)) <= 2)
    {
        return true;
    }
    return false;
}
int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    // Please write your code here.
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(Compare(i, j, k)) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}