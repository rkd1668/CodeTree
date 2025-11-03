#include <iostream>
#include <algorithm>
using namespace std;

bool IsEqualArray(int arr[], int myarr[]) {
    sort(myarr, myarr + 15);
    for(int i = 0; i < 15; i++) {
        if(arr[i] != myarr[i]) return false;
    }
    return true;
}

int main() {
    // Please write your code here.
    int arr[15];
    for(int i = 0; i < 15; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 15);

    int a = 0, b = 0;
    a = arr[0];
    b = arr[1];
    int sum_ab = a + b;
    for(int c = b; c <= 40; c++) {
        for(int d = c; d <= 40; d++) {
            int myarr[15] = {};
            myarr[0] = a;
            myarr[1] = b;
            myarr[2] = c;
            myarr[3] = a + b;
            myarr[4] = b + c;
            myarr[5] = c + d;
            myarr[6] = d + a;
            myarr[7] = a + c;
            myarr[8] = b + d;
            myarr[9] = a + b + c;
            myarr[10] = a + b + d;
            myarr[11] = a + c + d;
            myarr[12] = b + c + d;
            myarr[13] = d;
            myarr[14] = a + b + c + d;
            if(IsEqualArray(arr, myarr)) {
                cout << a << " " << b << " " << c << " " << d;
            }
        }
    }
    return 0;
}