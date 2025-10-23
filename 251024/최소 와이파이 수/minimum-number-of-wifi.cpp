#include <iostream>

using namespace std;

int n, m;
int arr[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 0;
    int i = 0;
    while(i < n) {
        if(arr[i] == 1) {
            ans++;
            i += m * 2 + 1;
        }
    }
    
    cout << ans;
}