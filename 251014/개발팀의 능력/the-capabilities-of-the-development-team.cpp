#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[5];

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
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = INT_MAX;
    bool check = false;
    int total = 0;
    for(int i = 0; i < 5; i++) {
        total += arr[i];
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(i == j || j == k || k == i) continue;
                int a = arr[i];
                int b = arr[j] + arr[k];
                int c = total - a - b;
                if(a == b || b == c || c == a) continue;
                int diff = GetMax(a, b, c) - GetMin(a, b, c);
                if(diff < ans) {
                    ans = diff;
                    check = true;
                }
            }
        }
    }

    if(!check) ans = -1;
    cout << ans;
    return 0;
}