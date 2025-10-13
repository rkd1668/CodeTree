#include <iostream>

using namespace std;

int N;
int pos[100];
char alpha[100];
char arr[101];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pos[i] >> alpha[i];
    }

    // Please write your code here.
    for(int i = 0; i < N; i++) {
        arr[pos[i]] = alpha[i];
    }

    int ans = 0;
    for(int i = 0; i < 101; i++) {
        for(int j = i; j < 101; j++) {
            int Gcnt = 0, Hcnt = 0;
            if(arr[i] == 'H' && arr[j] == 'H') {
                for(int k = i; k <= j; k++) {
                    if(arr[k] == 'G') Gcnt++;
                    else if(arr[k] == 'H') Hcnt++;
                }
                if(Gcnt == 0 || Hcnt == 0 || Gcnt == Hcnt) {
                    int dist = j - i;
                    if(ans < dist) ans = dist;
                }
            }
        }
    }

    cout << ans;
    return 0;
}