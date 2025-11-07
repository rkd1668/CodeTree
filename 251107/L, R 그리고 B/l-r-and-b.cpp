#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    char arr[10][10];
    int bx, by, rx, ry, lx, ly;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'B') {
                bx = j;
                by = i;
            }
            if(arr[i][j] == 'R') {
                rx = j;
                ry = i;
            }
            if(arr[i][j] == 'L') {
                lx = j;
                ly = i;
            }
        }
    }

    int ans = 0;
    if((bx == rx && rx == lx && (by - ry) * (ly - ry) < 0) || (by == ry && ry == ly && (bx - rx) * (lx - rx) < 0)) {
        ans = abs(bx - lx) + abs(by - ly) - 1 + 2;
    }
    else {
        ans = abs(bx - lx) + abs(by - ly) - 1;
    }
    
    cout << ans;
    return 0;
}