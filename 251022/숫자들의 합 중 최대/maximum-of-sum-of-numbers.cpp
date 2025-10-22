#include <iostream>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int ans = 0;
    for(int i = X; i <= Y; i++) {
        int sum = 0;
        int number = i;
        while(number > 0) {
            sum += number % 10;
            number /= 10;
        }
        if(sum > ans) ans = sum;
    }

    cout << ans;
    return 0;
}