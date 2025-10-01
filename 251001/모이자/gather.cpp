#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    int min_val = INT_MAX;

    for(int i = 0; i < n; i++) {
        int sum_dist = 0;
        for(int j = 0; j < n; j++) {
            sum_dist += A[j] * abs(i - j);
        }

        if(sum_dist < min_val) {
            min_val = sum_dist;
        }
    }
    cout << min_val;
    return 0;
}