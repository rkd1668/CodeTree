#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int arr[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 2; j++) {
            for(int k = 0; k < N; k++) {
                for(int l = 0; l < N - 2; l++) {
                    if(i == k && abs(j - l) < 3) continue;
                    int grid = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[k][l] + arr[k][l + 1] + arr[k][l + 2];
                    if(grid > ans) ans = grid; 
                }
            }
        }
    }

    cout << ans;
    return 0;
}