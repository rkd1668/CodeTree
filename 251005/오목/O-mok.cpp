#include <iostream>

using namespace std;

int board[19][19];

bool InRange(int i, int j) {
    return (i >= 0 && i < 19 && j >= 0 && j < 19);
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    // Please write your code here.
    int end = 0;
    int win_x = 0, win_y = 0;
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(board[i][j] == 1 || board[i][j] == 2) {
                int count1 = 1, count2 = 1, count3 = 1, count4 = 1;
                for(int k = 1; k <= 4; k++) {
                    if(InRange(i, j + k) && board[i][j + k] == board[i][j]) count1++;
                    if(InRange(i + k, j) && board[i + k][j] == board[i][j]) count2++;
                    if(InRange(i + k, j + k) && board[i + k][j + k] == board[i][j]) count3++;
                    if(InRange(i + k, j - k) && board[i + k][j - k] == board[i][j]) count4++;
                }

                if(count1 == 5 || count2 == 5 || count3 == 5 || count4 == 5) {
                    end = board[i][j];
                    if(count1 == 5) {
                        win_x = i + 1;
                        win_y = j + 3;
                    }
                    else if(count2 == 5) {
                        win_x = i + 3;
                        win_y = j + 1;
                    }
                    else if(count3 == 5) {
                        win_x = i + 3;
                        win_y = j + 3;
                    }
                    else if(count4 == 5) {
                        win_x = i + 3;
                        win_y = j - 1;
                    }
                }
            }
        }
    }

    cout << end << endl;
    if(end != 0) cout << win_x << " " << win_y;
    return 0;
}