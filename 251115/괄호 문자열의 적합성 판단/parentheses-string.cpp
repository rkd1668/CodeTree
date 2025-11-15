#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    string str;
    cin >> str;
    stack<char> st;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {
            st.push(str[i]);
        }
        else {
            if(st.empty() == true) {
                cout << "No" << endl;
                return 0;
            }
            else {
                st.pop();
            }
        }
    }

    if(st.empty() == false) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
}