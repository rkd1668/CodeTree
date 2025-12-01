#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[5] = {0, -1, 0, 0, 1};
int dy[5] = {0, 0, -1, 1, 0};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

class Marble {
public:
    int r, c;   
    int d;     
    int v;      
    int num;    
    Marble(int r, int c, int d, int v, int num) {
        this->r = r;
        this->c = c;
        this->d = d;
        this->v = v;
        this->num = num;
    };
};

int main() {

    int n, m, t, k;
    cin >> n >> m >> t >> k;

    vector<Marble> Marbles;
    Marbles.reserve(m);

    // 각 칸에 있는 구슬 개수
    vector<vector<int>> cnt(n, vector<int>(n, 0));

    // 입력
    for (int i = 0; i < m; i++) {
        int r, c, v, dir;
        char d;
        cin >> r >> c >> d >> v;

        // 방향 문자 -> 숫자 (너가 쓰던 방식 그대로)
        if (d == 'U') dir = 1;
        else if (d == 'D') dir = 4;
        else if (d == 'R') dir = 3;
        else dir = 2; // 'L'

        int x = r - 1;
        int y = c - 1;

        Marbles.push_back(Marble(x, y, dir, v, i + 1));
        cnt[x][y]++;
    }

    // t초 동안 시뮬레이션
    for (int step = 0; step < t; step++) {
        // 1. 모든 구슬 이동
        for (int i = 0; i < (int)Marbles.size(); i++) {
            int x = Marbles[i].r;
            int y = Marbles[i].c;
            int d = Marbles[i].d;
            int v = Marbles[i].v;

            // v번 한 칸씩 이동
            for (int s = 0; s < v; s++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // 범위를 벗어나면 방향 반대로
                if (!InRange(nx, ny, n)) {
                    d = 5 - d; // 1<->4, 2<->3
                    nx = x + dx[d];
                    ny = y + dy[d];
                }

                // 한 칸 실제로 이동
                cnt[x][y]--;
                x = nx;
                y = ny;
                cnt[x][y]++;
            }

            // 구슬 상태 반영
            Marbles[i].r = x;
            Marbles[i].c = y;
            Marbles[i].d = d;
        }

        // 2. 각 칸에서 k개 초과면 우선순위 낮은 구슬 제거
        //    → 느린(v 작은) + 번호(num 작은)부터 제거
        vector<bool> removed(Marbles.size(), false);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (cnt[x][y] > k) {
                    // 이 칸에 있는 구슬 index들 모으기
                    vector<int> idx;
                    for (int i = 0; i < (int)Marbles.size(); i++) {
                        if (Marbles[i].r == x && Marbles[i].c == y) {
                            idx.push_back(i);
                        }
                    }

                    int exceed = (int)idx.size() - k;
                    if (exceed <= 0) continue;

                    // 우선순위 낮은 순서: v 오름차순, num 오름차순
                    sort(idx.begin(), idx.end(), [&](int a, int b) {
                        if (Marbles[a].v != Marbles[b].v)
                            return Marbles[a].v < Marbles[b].v; // 느린 것 먼저
                        return Marbles[a].num < Marbles[b].num; // 번호 작은 것 먼저
                    });

                    // 초과 개수만큼 제거 표시
                    for (int i = 0; i < exceed; i++) {
                        removed[idx[i]] = true;
                    }
                }
            }
        }

        // 3. 제거된 것 빼고 새 벡터 구성 + cnt 다시 계산
        vector<Marble> nextMarbles;
        nextMarbles.reserve(Marbles.size());

        // cnt 초기화
        for (int i = 0; i < n; i++) {
            fill(cnt[i].begin(), cnt[i].end(), 0);
        }

        for (int i = 0; i < (int)Marbles.size(); i++) {
            if (!removed[i]) {
                nextMarbles.push_back(Marbles[i]);
                cnt[Marbles[i].r][Marbles[i].c]++;
            }
        }

        Marbles.swap(nextMarbles);
    }

    // t초 후 남은 구슬 개수 출력
    cout << Marbles.size() << '\n';

    return 0;
}
