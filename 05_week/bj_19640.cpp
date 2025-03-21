#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 사람 정보를 저장하는 구조체
struct Person {
    int days, priority, index, line;

    // 우선순위 큐 정렬 기준 (최대 힙)
    bool operator<(const Person &other) const {
        if (days != other.days) return days < other.days;  // 근무일 많은 사람이 우선
        if (priority != other.priority) return priority < other.priority; // 급한 사람 우선
        return line > other.line; // 줄 번호 작은 사람이 우선
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<queue<Person>> lines(M);  // 각 줄을 저장하는 큐 배열
    priority_queue<Person> pq; // 우선순위 큐 (최대 힙)

    int target_index = K;  // 데카의 위치

    for (int i = 0; i < N; i++) {
        int d, h;
        cin >> d >> h;
        lines[i % M].push({d, h, i, i % M}); // 각 줄에 사원 추가
    }

    // 각 줄의 맨 앞 사람만 우선순위 큐에 삽입
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    int rank = 0; // 처리 순서
    while (!pq.empty()) {
        Person cur = pq.top();
        pq.pop();

        if (cur.index == target_index) { // 데카의 차례가 되면 출력 후 종료
            cout << rank << '\n';
            return 0;
        }

        rank++; // 한 사람 처리 후 순위 증가

        // 현재 줄에서 다음 사람을 우선순위 큐에 추가
        if (!lines[cur.line].empty()) {
            pq.push(lines[cur.line].front());
            lines[cur.line].pop();
        }
    }

    return 0;
}
