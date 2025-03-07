#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 공약수 구하기 (feat.유클리드 호제법)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> positions(N);
    for (int i = 0; i < N; i++) {
        cin >> positions[i];
    }

    // 모든 거리 차이 계산산
    vector<int> diffs(N);
    for (int i = 0; i < N; i++) {
        diffs[i] = abs(positions[i] - S);
    }

    // 거리 차이들의 최대 공약수 구하기
    int result = diffs[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, diffs[i]);
    }

    cout << result << endl;
    return 0;
}
