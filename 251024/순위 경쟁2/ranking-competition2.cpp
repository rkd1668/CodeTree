#include <iostream>

using namespace std;

int n;
char c[100];
int s[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    // Please write your code here.
    int ans = 0;
    int ascore = 0, bscore = 0;
    int honor = 0;

    for(int i = 0; i < n; i++) {
        if(c[i] == 'A') ascore += s[i];
        else bscore += s[i];
        
        int temp = 0;
        if(ascore > bscore) temp = 1;
        else if(ascore < bscore) temp = 2;

        if(temp != honor) {
            honor = temp;
            ans++;
        }
    }

    cout << ans;
    return 0;
}