#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t, k;
    cin >> t;
    vector<string> gear(t);
    for (int i = 0; i < t; i++) cin >> gear[i];

    cin >> k;
    while (k--) {
        int n, d;
        cin >> n >> d;
        n--; // 0-based

        vector<int> dir(t, 0);
        dir[n] = d;

        // 왼쪽 전파
        for (int i = n - 1; i >= 0; i--) {
            if (gear[i][2] != gear[i + 1][6]) dir[i] = -dir[i + 1];
            else break;
        }

        // 오른쪽 전파
        for (int i = n + 1; i < t; i++) {
            if (gear[i - 1][2] != gear[i][6]) dir[i] = -dir[i - 1];
            else break;
        }

        // 회전 적용
        for (int i = 0; i < t; i++) {
            if (dir[i] == 0) continue;
            if (dir[i] == 1)
                gear[i] = gear[i].back() + gear[i].substr(0, 7);
            else
                gear[i] = gear[i].substr(1) + gear[i][0];
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; i++) if (gear[i][0] == '1') cnt++;
    cout << cnt << "\n";
    return 0;
}
