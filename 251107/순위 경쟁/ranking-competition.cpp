#include <iostream>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int arr[3] = {0, 0, 0};
    int honor[3] = {1, 1, 1};
    int ans = 0;
    

    for(int i = 0; i < n; i++) {
        char c;
        int s;
        cin >> c >> s;
        if(c == 'A') arr[0] += s;
        else if(c == 'B') arr[1] += s;
        else arr[2] += s;

        int temp[3] = {0, 0, 0};
        int max_score = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(arr[i] > max_score) max_score = arr[i];
        }
        for(int i = 0; i < 3; i++) {
            if(arr[i] == max_score) temp[i] = 1;
        }
        for(int i = 0; i < 3; i++) {
            if(honor[i] != temp[i]) {
                ans++;
                break;
            }
        }
        for(int i = 0; i < 3; i++) {
            honor[i] = temp[i];
        }
    }

    cout << ans;
    return 0;
}