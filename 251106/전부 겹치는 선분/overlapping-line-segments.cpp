#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> x1(n), x2(n);
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    vector<int> check(101);
    for(int i = 0; i < n; i++) {
        for(int j = x1[i]; j <= x2[i]; j++) {
            check[j]++;
        }
    }

    bool yes = false;
    for(int i = 0; i < 101; i++) {
        if(check[i] >= n) yes = true;
    }

    if(yes) cout << "Yes";
    else cout << "No";
    return 0;
}