#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> point;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }
  
    bool ans = false;
    for(int i = 0; i <= 21; i++) {
        for(int j = 0; j <= 21; j++) {
            for(int k = 0; k <= 21; k++) {
                bool is_possible = true;
                for(int l = 0; l < n; l++) {
                    if(point[l][0] == i || point[l][0] == j || point[l][0] == k || point[l][1] == i - 11 || point[l][1] == j - 11 || point[l][1] == k - 11) {
                        continue;
                    }
                    is_possible = false;
                }
                if(is_possible) ans = true;
            }
        }
    }

    if(ans) cout << 1;
    else cout << 0;
    return 0;
}