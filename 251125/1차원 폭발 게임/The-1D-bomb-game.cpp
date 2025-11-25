#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool explosion = true;
    while(explosion) {
        bool check = true;
        int cnt = 1;
        int start = 0, end = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(i < arr.size() && arr[i] == arr[i + 1]) {
                cnt++;
                end = i + 1;
            }
            if(arr[i] != arr[i + 1] || i == arr.size() - 2) {
                if(cnt >= m) {
                    for(int j = start; j <= end; j++) {
                        arr[j] = 0;
                    }
                    check = false;
                }
                cnt = 1;
                start = i + 1;
                end = i + 1;
            }
        }

        vector<int> temp;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) {
                temp.push_back(arr[i]);
            }
        }
        arr = temp;
        if(check) explosion = false;
    }

    cout << arr.size() << endl;
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    return 0;
}