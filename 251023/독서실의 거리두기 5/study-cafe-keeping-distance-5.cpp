#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int min_dist = INT_MAX;
        if(seat[i] == '1') continue;
        seat[i] = '1';
        for(int j = 0; j < N; j++) {
            int dist = 0;
            bool isone = false;
            if(seat[j] == '1') {
                for(int k = j + 1; k < N; k++) {
                    dist++;
                    if(seat[k] == '1') {
                        isone = true;
                        break;
                    }
                }
                if(isone) {
                    if(min_dist > dist) min_dist = dist;
                }
                
            }
        }
        if(min_dist > ans) ans = min_dist;
        seat[i] = '0';
    }

    cout << ans;
    return 0;
}