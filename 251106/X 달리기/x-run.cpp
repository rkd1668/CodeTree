#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int x;
    cin >> x;
    vector<int> t_max_d;
    t_max_d.push_back(1);
    t_max_d.push_back(2);
    t_max_d.push_back(4);
    t_max_d.push_back(6);
    for(int i = 4; i < 10000; i++) {
        t_max_d.push_back(i + 1 + t_max_d[i - 2]);
        if(i + 1 + t_max_d[i - 2] >= x) {
            cout << i + 1;
            break;
        } 
    }
    return 0;
}