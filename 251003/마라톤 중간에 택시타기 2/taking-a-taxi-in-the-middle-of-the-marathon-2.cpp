#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int n;
int x[100];
int y[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n - 1; j++) {
            int temp = 0;
            int temp_x = x[j], temp_y = y[j];
            x[j] = x[j - 1];
            y[j] = y[j - 1];
            for(int k = 1; k < n; k++) {
                int dist = abs(x[k] - x[k - 1]) + abs(y[k] - y[k - 1]);
                temp += dist; 
            }
            if(ans > temp) ans = temp;
            x[j] = temp_x;
            y[j] = temp_y;
        }
    }

    cout << ans;
    return 0;
}