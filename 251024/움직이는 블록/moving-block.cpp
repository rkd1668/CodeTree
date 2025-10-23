#include <iostream>

using namespace std;

int n;
int blocks[10000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    // Please write your code here.
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += blocks[i];
    }
    int avg = sum / n;

    for(int i = 0; i < n; i++) {
        if(blocks[i] < avg) {
            ans += avg - blocks[i];
        }
    }

    cout << ans;
    return 0;
}