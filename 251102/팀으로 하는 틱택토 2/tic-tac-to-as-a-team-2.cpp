#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    vector<vector<int>> v1(3, vector<int>(3));
    for(int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < 3; j++) {
            int digit = n % 10;
            v1[i][2 - j] = digit;
            n /= 10;
        }
    }

    vector<vector<int>> way(8, vector<int>(3));
    for(int i = 0; i < 3; i++) {
        way[0][i] = v1[0][i];
        way[1][i] = v1[1][i];
        way[2][i] = v1[2][i];
        way[3][i] = v1[i][0];
        way[4][i] = v1[i][1];
        way[5][i] = v1[i][2];
        way[6][i] = v1[i][i];
        way[7][i] = v1[i][2 - i];
    }

    int ans = 0;
    vector<int> v2(8);
    for(int i = 0; i < 8; i++) {
        if(way[i][0] == way[i][1] && way[i][1] == way[i][2]) v2[i] = 1;
    }

    for(int i = 1; i < 9; i++) {
        for(int j = i + 1; j <= 9; j++) {
            bool check = false;
            for(int k = 0; k < 8; k++) {
                if(v2[k] == 1) continue;
                bool is_possible = true;
                for(int l = 0; l < 3; l++) {
                    if(way[k][l] == i || way[k][l] == j) continue;
                    is_possible = false;   
                }
                if(is_possible) check = true;
            }
            if(check) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}