#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int ability[6];

int GetMax(int a, int b, int c) {
    int max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    return max;
}

int GetMin(int a, int b, int c) {
    int min = a;
    if(min > b) min = b;
    if(min > c) min = c;
    return min;
}
int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
    }

    // Please write your code here.
    int ans = INT_MAX;
    int total = 0;
    for(int i = 0; i < 6; i++) {
        total += ability[i];
    }

    for(int i = 1; i < 6; i++) {
        for(int j = 1; j < 6; j++) {
            if(i == j) continue;
            for(int k = 1; k < 6; k++) {
                if(k == i || k == j) continue;
                int a = ability[0] + ability[i];
                int b = ability[j] + ability[k];
                int c = total - a - b;
                int diff = GetMax(a, b, c) - GetMin(a, b, c);
                if(diff < ans) ans = diff;
            }
        }
    }
    cout << ans;
    return 0;
}