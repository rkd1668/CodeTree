#include <iostream>
#include <vector>
using namespace std;

bool CheckPelindrome(int n) {
    vector<int> digit;
    int number = n;

    while(number > 0) {
        digit.push_back(number % 10);
        number /= 10;
    }
    int size = digit.size();
    for(int i = 0; i < size / 2; i++) {
        if(digit[i] != digit[size - 1 - i]) return false;
    }
    return true;
}

int main() {
    // Please write your code here.
    int x, y;
    cin >> x >> y;

    int ans = 0;
    for(int i = x; i <= y; i++) {
        if(CheckPelindrome(i)) ans++;
    }

    cout << ans;
    return 0;
}