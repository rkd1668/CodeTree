#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N, M, D, S;
    cin >> N >> M >> D >> S;

    vector<int> p(D), m(D), t(D), sick_p(S), sick_t(S);

    for(int i = 0; i < D; i++) {
        cin >> p[i] >> m[i] >> t[i];
    } 
    for(int i = 0; i < S; i++) {
        cin >> sick_p[i] >> sick_t[i];
    }

    int ans = 0;
    for(int i = 1; i <= M; i++) {
        bool is_possible1 = true;
        int cnt = 0;
        for(int j = 0; j < S; j++) {
            bool is_possible2 = false;
            for(int k = 0; k < D; k++) {
                if(p[k] == sick_p[j] && m[k] == i && sick_t[j] > t[k]) {
                    is_possible2 = true;
                    break;
                }
            }
            if(!is_possible2) is_possible1 = false;
        }
        
        if(is_possible1) {
            for(int j = 1; j <= N; j++) {
                for(int k = 0; k < D; k++) {
                    if(j == p[k] && m[k] == i) {
                        cnt++;
                        break;
                    }
                }
            }
        }


        if(ans < cnt) ans = cnt;
    }

    cout << ans;
    return 0;
}