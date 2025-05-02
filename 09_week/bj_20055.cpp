#include <iostream>
#include <deque>
#include <algorithm> 
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> durability(2 * n);
    deque<bool> robots(n, false);

    for (int i = 0; i < 2 * n; i++) {
        cin >> durability[i];
    }

    int step = 0;
    while (true) {
        step++;

        // 1. 벨트 회전
        durability.push_front(durability.back());
        durability.pop_back();
        robots.push_front(false);
        robots.pop_back();

        // 2. 로봇 이동
        for (int i = n - 2; i >= 0; i--) {
            if (robots[i] && !robots[i + 1] && durability[i + 1] > 0) {
                robots[i] = false;
                robots[i + 1] = true;
                durability[i + 1]--;
            }
        }
        robots[n - 1] = false; // 내리는 위치

        // 3. 로봇 올리기
        if (durability[0] > 0) {
            robots[0] = true;
            durability[0]--;
        }

        // 4. 종료 조건
        int zero_count = count(durability.begin(), durability.end(), 0);
        if (zero_count >= k) break;
    }

    cout << step << "\n";
    return 0;
}
