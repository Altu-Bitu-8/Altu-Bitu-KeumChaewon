#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<char> used(n, 0); // char로 변경: 0은 false, 1은 true
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (s[j] == 'H' && !used[j]) {
                    used[j] = 1;
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}
