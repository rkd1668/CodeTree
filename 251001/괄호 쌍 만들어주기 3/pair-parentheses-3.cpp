#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < A.length() - 1; i++) {
        if(A[i] == '(')
        {
            for(int j = i + 1; j < A.length(); j++) {
                if(A[j] == ')') {
                    ans++;
                }
           }
        }
    }

    cout << ans;
    return 0;
}