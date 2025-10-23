#include <iostream>
#include <algorithm>

using namespace std;

int arr[7];

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    sort(arr, arr + 7);
    int a = arr[0];
    int b = arr[1];
    int c = arr[6] - arr[0] - arr[1];

    cout << a << " " << b << " " << c << endl;
    return 0;
}