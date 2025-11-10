#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "size") {
            cout << v.size() << endl;
        }
        else if(str == "pop_back") {
            v.pop_back();
        }
        else {
            int n;
            cin >> n;
            if(str == "push_back") {
                v.push_back(n);
            }
            else if(str == "get") {
                cout << v[n - 1] << endl;
            }
        }
    }
    return 0;
}