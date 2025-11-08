#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> plus, minus;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] >= 0) plus.push_back(v[i]);
        else minus.push_back(v[i] * (-1));
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    
    int ans = 0;
    int num1 = 0, num2 = 0;
    if(plus.empty()) {
        ans = minus[0] * minus[1] * minus[2] * (-1);
    }
    else if(n == 3) {
        ans = v[0] * v[1] * v[2];
    }
    else {
        int p_size = plus.size();
        int m_size = minus.size();
        if(p_size >= 3) {
            num1 = plus[p_size - 1] * plus[p_size - 2] * plus[p_size - 3];  
        }
        if(m_size >= 2) {
            num2 = minus[m_size - 1] * minus[m_size - 2] * plus[p_size - 1];
        }

        if(num1 >= num2) ans = num1;
        else ans = num2;
    }

    cout << ans;
    return 0;
}