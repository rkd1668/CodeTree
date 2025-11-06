#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, m, p;
    cin >> n >> m >> p;

    vector<char> name(m);
    vector<int> count(m);
    for(int i = 0; i < m; i++) {
        cin >> name[i] >> count[i];
    }

    char c = 'A';
    vector<char> check(n);
    for(int i = 0; i < n; i++) {
        check[i] = c + i;
    }

    if(count[p - 1] > 0) {
        for(int i = p - 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(name[i] == check[j]) {
                    check[j] = 0;
                }
            }
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            check[i] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(check[i] == 0) continue;
        cout << check[i] << " ";
    }
    return 0;
}