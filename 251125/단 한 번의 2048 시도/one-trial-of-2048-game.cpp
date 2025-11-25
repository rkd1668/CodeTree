#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    vector<vector<int>> grid(4, vector<int>(4));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }
    char d;
    cin >> d;

    if(d == 'R') {
        vector<vector<int>> temp(4, vector<int>(4));
        for(int i = 0; i < 4; i++) {
            int temp_c = 3;
            bool check = true;
            for(int j = 3; j >= 0; j--) {
                if(grid[i][j] != 0) {
                    temp[i][temp_c] = grid[i][j];
                    if(temp_c < 3 && temp[i][temp_c] == temp[i][temp_c + 1] && check) {
                        temp[i][temp_c + 1] *= 2;
                        temp[i][temp_c] = 0;
                        check = false;
                    }
                    else {
                        temp_c--;
                        check = true;
                    }
                    
                }
            }
        }
        grid = temp;
    }
    else if(d == 'L') {
        vector<vector<int>> temp(4, vector<int>(4));
        for(int i = 0; i < 4; i++) {
            int temp_c = 0;
            bool check = true;
            for(int j = 0; j < 4; j++) {
                if(grid[i][j] != 0) {
                    temp[i][temp_c] = grid[i][j];
                    if(temp_c > 0 && temp[i][temp_c] == temp[i][temp_c - 1] && check) {
                        temp[i][temp_c - 1] *= 2;
                        temp[i][temp_c] = 0;
                        check = false;
                    }
                    else {
                        temp_c++;
                        check = true;
                    }
                    
                }
            }
        }
        grid = temp;
    }
    else if(d == 'U') {
        vector<vector<int>> temp(4, vector<int>(4));
        for(int j = 0; j < 4; j++) {
            int temp_r = 0;
            bool check = true;
            for(int i = 0; i < 4; i++) {
                if(grid[i][j] != 0) {
                    temp[temp_r][j] = grid[i][j];
                    if(temp_r > 0 && temp[temp_r][j] == temp[temp_r - 1][j] && check) {
                        temp[temp_r - 1][j] *= 2;
                        temp[temp_r][j] = 0;
                        check = false;
                    }
                    else {
                        temp_r++;
                        check = true;
                    }
                    
                }
            }
        }
        grid = temp;
    }
    else if(d == 'D') {
        vector<vector<int>> temp(4, vector<int>(4));
        for(int j = 0; j < 4; j++) {
            int temp_r = 3;
            bool check = true;
            for(int i = 3; i >= 0; i--) {
                if(grid[i][j] != 0) {
                    temp[temp_r][j] = grid[i][j];
                    if(temp_r < 3 && temp[temp_r][j] == temp[temp_r + 1][j] && check) {
                        temp[temp_r + 1][j] *= 2;
                        temp[temp_r][j] = 0;
                        check = false;
                    }
                    else {
                        temp_r--;
                        check = true;
                    }
                    
                }
            }
        }
        grid = temp;
    }




    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}