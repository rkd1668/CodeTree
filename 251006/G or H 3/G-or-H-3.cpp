#include <iostream>

using namespace std;

int N, K;
int x[100];
char c[100];
int placed[10001];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> c[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(c[i] == 'G') {
            placed[x[i]] = 1;
        }
        else {
            placed[x[i]] = 2;
        }
    }

    for(int i = 1; i < 10001 - K; i++) {
        int sum = 0;
        for(int j = 0; j <= K; j++) {
            sum += placed[i + j];
        }
        if(sum > ans) ans = sum;
    }

    cout << ans;
    return 0;
}