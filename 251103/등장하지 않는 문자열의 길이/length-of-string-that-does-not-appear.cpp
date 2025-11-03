#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    string str1;
    vector<char> str(n);
    cin >> n;
    cin >> str1;
    for(int i = 0; i < n; i++) {
        str[i] = str1[i];
    }

    int ans = 0;
    bool check = false;
    for(int i = 1; i <= n / 2; i++) {
        if(!check) {
            for(int j = 0; j <= n - i; j++) {
                vector<char> sub(i);
                int cnt = 0;
                for(int k = 0; k < i; k++) {
                    sub[k] = str[j + k]; 
                }

                for(int k = 0; k <= n - i; k++) {
                    bool check2 = true;
                    for(int l = 0; l < i; l++) {
                        if(sub[l] == str[k + l]) continue;
                        check2 = false;
                    }
                    if(check2) cnt++;
                }
                if(cnt >= 2) break;
                if(j == n - i) {
                    check = true;
                    ans = i;
                }
            }
        }
    }

    cout << ans;

    return 0;
}