#include <iostream>

using namespace std;

int N, M;
int A[100], B[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i <= N - M; i++) {
        int C[100] = {0, };
        for(int j = 0; j < M; j++) {
            bool check = false;
            for(int k = 0; k < M; k++) {
                if(A[i + j] == B[k] && C[k] == 0) {
                    check = true;
                    C[k] = 1;
                    break;
                }
            }
            if(check == false) break;
            else if(check == true && j == M - 1) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}