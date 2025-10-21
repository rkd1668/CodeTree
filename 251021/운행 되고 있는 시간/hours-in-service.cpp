#include <iostream>

using namespace std;

int N;
int A[100], B[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int work_time[1000] = {0, };
        int time = 0;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            for(int k = A[j]; k < B[j]; k++) {
                if(work_time[k] != 1) work_time[k] = 1;
            }  
        }
        for(int k = 0; k < 1000; k++) {
                time += work_time[k];
            }

            if(time > ans) ans = time;
    }
    cout << ans;
    return 0;
}