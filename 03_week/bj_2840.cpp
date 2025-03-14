#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, K;
    cin >> n >> K;

    vector<char> wheel(n, '?'); 
    unordered_map<char, bool> used; // 사용된 알파벳

    int pos = 0;

    for (int i=0; i<K; i++) {
        int s;
        char c;
        cin >> s >> c;

        pos = (pos - s%n + n) % n;  // 시계방향으로 s 이동

        // 예외1) 같은 위치 다른 문자
        if (wheel[pos] != '?' && wheel[pos] != c) {
            cout << "!" << endl;
            return 0;
        }

        // 예외2) 알파벳 중복
        if (wheel[pos] == '?' && used[c]) {
            cout << "!" << endl;
            return 0;
        }

        wheel[pos] = c;
        used[c] = true;
    }

    // 바퀴의 최종 상태
    for (int i = 0; i < n; i++) {
        cout << wheel[(pos + i) % n];
    }
    cout << endl;

    return 0;
}
