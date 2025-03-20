#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;
        pq.push(num);
        if (pq.size() > N) pq.pop(); // 항상 N개의 요소만 유지
    }

    cout << pq.top() << '\n'; // N번째 큰 수
    return 0;
}
