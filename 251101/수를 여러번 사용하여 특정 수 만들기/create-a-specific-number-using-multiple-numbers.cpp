#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 500; j++) {
            int sum = a * i + b * j;
            if(sum <= c && sum > ans) ans = sum;
        }
    }

    cout << ans;
    return 0;
}