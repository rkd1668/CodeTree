#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
void ChooseHorse(vector<int> input, vector<int> arr, int cnt, int n, int m, int k) {
    if(cnt == n) {
        int count = 0;
        for(int i = 0; i < k; i++) {
            if(arr[i] >= m - 1) count++;
        }
        if(count > ans) ans = count;
        return;
    }

    for(int i = 1; i <= k; i++) {
        arr[i - 1] += input[cnt];
        ChooseHorse(input, arr, cnt + 1, n, m, k);
        arr[i - 1] -= input[cnt];
    }
}
int main() {
    // Please write your code here.
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(k);
    vector<int> input(n);
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    ChooseHorse(input, arr, 0, n, m, k);

    cout << ans;
    return 0;
}