#include <iostream>
#include <string>

using namespace std;

int N, M;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
string arr[50];

bool InRange(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 'L') {
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int nnx = nx + dx[k];
                    int nny = ny + dy[k];
                    if(InRange(nx, ny) && arr[nx][ny] == 'E' && InRange(nnx, nny) && arr[nnx][nny] == 'E') ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}