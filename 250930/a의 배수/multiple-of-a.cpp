#include <iostream>
using namespace std;

int N, a;
int main() {
    // Please write your code here.
    cin >> N >> a;
    int num = 1;
    while(num <= N) 
    {
        if(num % a == 0) 
        {
            cout << 1 << endl;
        }
        else 
        {
            cout << 0 << endl;
        }
        num++;
    }
    return 0;
}