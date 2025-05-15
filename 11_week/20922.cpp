#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;
int count[100001];

int main() {
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_length = 0;
    int start = 0, end = 0;

    while (end < n) {
        // 숫자 추가
        count[arr[end]]++;
        
        // K를 넘으면 시작점을 이동
        while (count[arr[end]] > k) {
            count[arr[start]]--;
            start++;
        }
        
        // 최대 길이 갱신
        max_length = max(max_length, end - start + 1);
        end++;
    }

    cout << max_length << '\n';
    return 0;
}
