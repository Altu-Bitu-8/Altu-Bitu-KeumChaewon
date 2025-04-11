#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {0, 1, 1, -1};
const int dy[4] = {1, 0, 1, 1};

int board[20][20];

bool is_valid(int x, int y) {
    return x >= 0 && x < 19 && y >= 0 && y < 19;
}

bool dfs(int x, int y, int dir, int color, int cnt) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (!is_valid(nx, ny) || board[nx][ny] != color) return cnt == 5;
    return dfs(nx, ny, dir, color, cnt + 1);
}

bool check_backward(int x, int y, int dir, int color) {
    int bx = x - dx[dir];
    int by = y - dy[dir];
    return is_valid(bx, by) && board[bx][by] == color;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j]) {
                for (int d = 0; d < 4; d++) {
                    if (!check_backward(i, j, d, board[i][j]) && dfs(i, j, d, board[i][j], 1)) {
                        cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
