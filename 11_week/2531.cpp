#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    unordered_map<int, int> counter;
    int max_count = 0, current_count = 0;

    // 초기 K개를 먹었을 때의 초밥 종류 수 계산
    for (int i = 0; i < k; i++) {
        if (counter[sushi[i]]++ == 0) current_count++;
    }
    // 쿠폰 초밥 추가
    if (counter[c]++ == 0) current_count++;
    max_count = current_count;

    // 슬라이딩 윈도우로 두 포인터 이동
    for (int i = 1; i < n; i++) {
        int remove_sushi = sushi[i - 1];
        int add_sushi = sushi[(i + k - 1) % n];

        // 초밥 제거
        if (--counter[remove_sushi] == 0) current_count--;

        // 초밥 추가
        if (counter[add_sushi]++ == 0) current_count++;

        max_count = max(max_count, current_count);
    }

    cout << max_count << '\n';
    return 0;
}
