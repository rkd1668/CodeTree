#include <iostream>

using namespace std;

int n;
int a[10], b[10], c[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    // Please write your code here.
    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {
                if(i == j || j == k || k == i) continue;
                for(int l = 0; l < n; l++) {
                    int cnt_b = 0, cnt_c = 0;
                    int one_number = a[l] % 10;
                    int ten_number = (a[l] / 10) % 10;
                    int hundred_number = a[l] / 100; 
                    if(hundred_number == i) cnt_b++;
                    else if(hundred_number == j || hundred_number == k) cnt_c++;
                    if(ten_number == j) cnt_b++;
                    else if(ten_number == i || ten_number == k) cnt_c++;
                    if(one_number == k) cnt_b++;
                    else if(one_number == i || one_number == j) cnt_c++;

                    if(cnt_b != b[l] || cnt_c != c[l]) break;
                    if(l == n - 1) ans++;
                }                                                
            }
        }
    }

    cout << ans;
    return 0;
}