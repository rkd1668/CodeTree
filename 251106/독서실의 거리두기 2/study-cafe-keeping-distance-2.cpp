#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    string seats;

    cin >> n >> seats;
    int max_dist = 0;
    int max_i = -1, max_j;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(seats[i] == '1') {
            for(int j = i + 1; j < n; j++) {
                cnt2++;
                if(seats[j] == '1') {
                    cnt2 = 0;
                    if(j - i > max_dist) {
                        max_dist = j - i;
                        max_i = i;
                        max_j = j;
                    }
                    break;
                }
            }
                
        }
        else if(max_i == -1) cnt1++;
    }
    
    if((max_j - max_i) / 2 > cnt1 && (max_j - max_i) / 2 > cnt2) {
        seats[(max_i + max_j) / 2] = '1';
    }
    else if(cnt1 >= cnt2) {
        seats[0] = '1';
    }
    else {
        seats[seats.size() - 1] = '1';
    }
    

    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(seats[i] == '1') {
            for(int j = i + 1; j < n; j++)
                if(seats[j] == '1') {
                    ans = min(ans, j - i);
                    break;
                }
        }
    }

    cout << ans;
    return 0;
}