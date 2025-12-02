#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = {0, -1, 1, 0}, dy[4] = {1, 0, 0, -1};
bool InRange(int x, int y) {
    return x >= 0 && x < 2001 && y >= 0 && y < 2001;
}

int main() {
    // Please write your code here.
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<tuple<int, int, int, int, int >> Marbles;
        for(int j = 0; j < n; j++) {
            int x, y, w, dir;
            char d;
            cin >> x >> y >> w >> d;
            if(d == 'U') dir = 0;
            else if(d == 'D') dir = 3;
            else if(d == 'L') dir = 1;
            else dir = 2;
            Marbles.push_back(make_tuple(x * 2, y * 2, -w, -(j + 1), dir));
        }
        int time = -1;
        for(int j = 1; j < 4001; j++) {
            int size = Marbles.size();
            if(size < 2) break;
            for(int k = 0; k < size; k++) {
                int w, num, dir, x , y;
                tie(x, y, w, num, dir) = Marbles[k];
                Marbles[k] = make_tuple(x + dx[dir], y + dy[dir], w, num, dir);
                //cout << num << ": " << x << " " << y << endl;
            }
            sort(Marbles.begin(), Marbles.end());
            vector<tuple<int, int, int, int, int >> temp;
            temp.push_back(Marbles[0]);
            for(int k = 0; k < size - 1; k++) {
                int w1, num1, dir1, x1, y1;
                int w2, num2, dir2, x2, y2;
                tie(x1, y1, w1, num1, dir1) = Marbles[k];
                tie(x2, y2, w2, num2, dir2) = Marbles[k + 1];
                if(x1 == x2 && y1 == y2) {
                    time = j;
                    continue;
                }
                else temp.push_back(Marbles[k + 1]);
            }
            Marbles = temp;
        }
        cout << time << endl;
    }


    return 0;
}