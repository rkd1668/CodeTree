#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(str == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(str == "pop_front") {
            cout << dq.front() << endl;
            dq.pop_front();
        }
        else if(str == "pop_back") {
            cout << dq.back() << endl;
            dq.pop_back();
        }
        else if(str == "size") {
            cout << dq.size() << endl;
        }
        else if(str == "front") {
            cout << dq.front() << endl;
        }
        else if(str == "empty") {
            if(dq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            cout << dq.back() << endl;
        }
    }
    return 0;
}