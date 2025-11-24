#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    } 

    int ans = INT_MIN;

    for(int p1x = 0; p1x < n; p1x++) {
        for(int p1y = 0; p1y < m; p1y++) {
            for(int p2x = p1x; p2x < n; p2x++) {
                for(int p2y = p1y; p2y < m; p2y++) {
                    for(int p3x = 0; p3x < n; p3x++) {
                        for(int p3y = 0; p3y < m; p3y++) {
                            for(int p4x = p3x; p4x < n; p4x++) {
                                for(int p4y = p3y; p4y < m; p4y++) {
                                    int sum = 0;
                                    if(p2x >= p3x && p2y >= p3y) continue;
                                    for(int i = p1x; i <= p2x; i++) {
                                        for(int j = p1y; j <= p2y; j++) {
                                            sum += grid[i][j];
                                        }
                                    }
                                    for(int i = p3x; i <= p4x; i++) {
                                        for(int j = p3y; j <= p4y; j++) {
                                            sum += grid[i][j];
                                        }
                                    }
                                    if(ans < sum) ans = sum;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}