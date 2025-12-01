#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

pair<int, int> GetPos(vector<vector<vector<int>>> grid, int x, int y, int n) {
    int num = 0;
    int next_x = x, next_y = y;
    for(int i = 0; i < 8; i++) {
        if(InRange(x + dx[i], y + dy[i], n)) {
            for(int j = 0; j < grid[x + dx[i]][y + dy[i]].size(); j++) {
                if(num < grid[x + dx[i]][y + dy[i]][j]) {
                    num = grid[x + dx[i]][y + dy[i]][j];
                    next_x = x + dx[i];
                    next_y = y + dy[i];
                }
            }

        } 
    }
    return make_pair(next_x, next_y);
}

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> grid(n, vector<vector<int>>(n, vector<int>(1)));
    vector<pair<int, int>> num_pos(n * n + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j][0];
            num_pos[grid[i][j][0]] = make_pair(i, j);
        }
    }
    
    for(int i = 0; i < m; i++) {
        int num;
        stack<int> st;
        cin >> num;
        int x = num_pos[num].first, y = num_pos[num].second;
        pair<int, int> next_pos = GetPos(grid, x, y, n);
        if(num_pos[num] == next_pos) continue;
        bool check = true;

        while(check) {
            st.push(grid[x][y].back());
            if(grid[x][y].back() == num) check = false;
            grid[x][y].pop_back();
        }
        int size = st.size();
        for(int j = 0; j < size; j++) {
            grid[next_pos.first][next_pos.second].push_back(st.top());
            num_pos[st.top()] = next_pos;
            st.pop();
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j].size() == 0) cout << "None";
            else {
                for(int k = grid[i][j].size() - 1; k >= 0; k--) {
                    cout << grid[i][j][k] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}