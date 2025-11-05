#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    vector<int> ans(n);
    
    for(int i = 1; i <= 1000; i++) {
        vector<int> check_v(n);
        check_v[i - 1] = 1;
        bool check = true;
        int number = i;
        for(int j = 0; j < n - 1; j++) {
            number = v[j] - number;
            if(check_v[number - 1] == 0) {
                check_v[number - 1] = 1;
                continue;
            }
            check = false;
            break;
        }
        if(check) {
            ans[0] = i;
            for(int j = 0; j < n - 1; j++) {
                ans[j + 1] = v[j] - ans[j];
            }
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}