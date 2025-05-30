#include <iostream>
#include <deque>
#include <queue>
#include <map>
using namespace std;

int n, k, l;
int board[101][101];
map<int, char> turn;
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t; char c;
        cin >> t >> c;
        turn[t] = c;
    }

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    int dir = 0, time = 0;
    board[1][1] = 2;

    while (true) {
        time++;
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2) break;

        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
            snake.push_front({nx, ny});
        } else {
            board[nx][ny] = 2;
            snake.push_front({nx, ny});
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        if (turn.count(time)) {
            if (turn[time] == 'D') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
        }
    }

    cout << time << "\n";
    return 0;
}
