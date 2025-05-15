#include <iostream>
using namespace std;

int n, m, r, c, d;
int room[50][50];
int cleaned = 0;

// 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int turn_left(int direction) {
    return (direction + 3) % 4;
}

int main() {
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> room[i][j];

    while (true) {
        // 현재 위치 청소
        if (room[r][c] == 0) {
            room[r][c] = 2;
            cleaned++;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            d = turn_left(d);
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0) {
                r = nx;
                c = ny;
                moved = true;
                break;
            }
        }

        // 네 방향 모두 청소되어 있거나 벽인 경우
        if (!moved) {
            int back = (d + 2) % 4;
            int bx = r + dx[back];
            int by = c + dy[back];

            if (bx < 0 || bx >= n || by < 0 || by >= m || room[bx][by] == 1) 
                break;  // 후진 불가 시 종료
            r = bx;
            c = by;
        }
    }

    cout << cleaned << '\n';
    return 0;
}
