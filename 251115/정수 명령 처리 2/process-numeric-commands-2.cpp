#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(str == "pop") {
            cout << q.front() << endl;
            q.pop();
        }
        else if(str == "size") {
            cout << q.size() << endl;
        }
        else if(str == "empty") {
            if(q.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            cout << q.front() << endl;
        }
    }
    return 0;
}