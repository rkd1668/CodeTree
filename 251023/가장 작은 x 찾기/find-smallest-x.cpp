#include <iostream>
#include <climits>

using namespace std;

int n;
int a[10], b[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.
    bool isfail = true;
    int x = 0;
    while(isfail) {
        x++;
        int temp = x;
        for(int i = 0; i < n; i++) {
            temp *= 2;
            if(temp < a[i] || temp > b[i]) break;
            if(i == n - 1) {
                isfail = false;
            }
        }
    }

    cout << x;
    return 0;
}