#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, total;
int ans = INT_MAX;
vector<int> arr;
vector<int> selected;

void GetAnswer() {
    int sum = 0;
    for(int i = 0; i < selected.size(); i++) {
        sum += selected[i];
    }
    int temp_ans = abs(total - 2 * sum) ;
    if(ans > temp_ans) ans = temp_ans;
}

void Choose(int idx, int cnt) {
    if(cnt == n) {
        GetAnswer();
        return;
    }

    for(int i = idx; i < 2 * n; i++) {
        selected.push_back(arr[i]);
        Choose(i + 1, cnt + 1);
        selected.pop_back();
    }
}
int main() {
    // Please write your code here.    
    cin >> n;
    arr.resize(n * 2);
    for(int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    Choose(0, 0);
    cout << ans;
    return 0;
}