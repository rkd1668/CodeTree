#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, H, T;
int arr[100];

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // Please write your code here.
    int ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            int sum = 0;
            if(j - i + 1 >= T) {
                for(int k = i; k <= j; k++) {
                    sum += abs(arr[k] - H);
                }
                if(ans > sum) ans = sum; 
            }
               
        }
    }

    cout << ans;
    return 0;
}