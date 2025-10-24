#include <iostream>
#include <string>
#include <list>

using namespace std;

int n, m;
string str;

int main() {
    cin >> n >> m;
    cin >> str;

    list<char> s;
    list<char>::iterator it;

    for(int i = 0; i < n; i++) {
        char c = str[i];
        s.push_back(c);
    }
    //s.push_back('0');
    it = s.end();

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if(command == 'L' && it != s.begin()) {
            it--;
        }
        else if(command == 'R' && it != s.end()) {
            it++;
        }
        else if(command == 'D' && it != s.end()) {
            s.erase(it);
        }
        else if (command == 'P') {
            char c;
            cin >> c;
            s.insert(it, c);
        }
    }

    // Please write your code here.
    for(it = s.begin(); it != s.end(); it++) {
        cout << *it;
    }
    return 0;
}
