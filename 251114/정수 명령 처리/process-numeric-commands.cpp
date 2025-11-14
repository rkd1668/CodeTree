#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "push") {
            int a;
            cin >> a;
            st.push(a);
        }
        else if(str == "pop") {
            cout << st.top() << endl;
            st.pop();
        }
        else if(str == "size") {
            cout << st.size() << endl;
        }
        else if(str == "empty") {
            if(st.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            cout << st.top() << endl;
        }
    }
    return 0;
}