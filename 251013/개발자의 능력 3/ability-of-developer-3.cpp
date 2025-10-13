#include <iostream>
#include <climits>

using namespace std;

int abilities[6];

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
    }

    // Please write your code here.
    int ans = INT_MAX;
    int sum = 0;
    
    for(int i = 0; i < 6; i++) {
        sum += abilities[i];
    }

    for(int i = 1; i < 5; i++) {
        for(int j = i + 1; j < 6; j++) {
            int temp = abilities[0];
            temp = temp + abilities[i] + abilities[j];
            int diff = abs((sum - temp) - temp);
            if(ans > diff) ans = diff;
        }
    }
    cout << ans;
    return 0;
}