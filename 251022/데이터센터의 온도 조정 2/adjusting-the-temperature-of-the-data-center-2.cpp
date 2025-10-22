#include <iostream>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i <= 1000; i++) {
        int work = 0;
        for(int j = 0; j < N; j++) {
            if(i < Ta[j]) work += C;
            else if(i >= Ta[j] && i <= Tb[j]) work += G;
            else work += H;
        }
        if(work > ans) ans = work;
    }

    cout << ans;
    return 0;
}