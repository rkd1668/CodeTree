#include <iostream>
#include <string>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    // Please write your code here.
    int x1 = 0, x2 = 0;
    int max_dist = 0;
    for(int i = 0; i < N - 1; i++) {
        if(seats[i] == '1') {
            int index = i + 1;
            int dist = 1;
            while(seats[index] == '0') {
                index++;
                dist++;
            }
            if(max_dist < dist) {
                max_dist = dist;
                x1 = i;
                x2 = index;
            }
        }
    }

    int ans = 10000;
    seats[(x1 + x2) / 2] = '1';
    for(int i = 0; i < N - 1; i++) {
        if(seats[i] == '1') {
            int index = i + 1;
            int dist = 1;
            while(seats[index] == '0') {
                index++;
                dist++;
            }
            if(ans > dist) ans = dist;
        }
    }

    cout << ans;
    return 0;
}