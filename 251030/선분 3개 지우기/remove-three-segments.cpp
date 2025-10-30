#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                int counting[101] = {0, };
                bool is_cross = false;
                for(int l = 0; l < n; l++) {
                    if(l == i || l == j || l == k) continue;
                    for(int m = v[l][0]; m <= v[l][1]; m++) {
                        counting[m]++;
                    }
                }
                for(int m = 0; m < 101; m++) {
                    if(counting[m] >= 2) {
                        is_cross = true;
                        break;
                    }
                }

                if(!is_cross) ans++;
            }
        }
    }

    cout << ans; 
    return 0;
}