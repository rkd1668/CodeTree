#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int k , n;
    cin >> k >> n;

    vector<vector<int>> v1(k, vector<int>(n + 1));
   
    for(int i = 0; i < k; i++) {
        for(int j = 1; j <= n; j++) {
            int number;
            cin >> number;
            v1[i][number] = j;
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <=n; j++) {
            if(i == j) continue; 
            bool high = true;  

            for(int a = 0; a <k; a++) {
                if(v1[a][i] > v1[a][j]) {
                    high = false;
                    break;
                }
            }
            if(high) ans++;
        }
    }    

    cout << ans;
    return 0;
}