#include <iostream>
using namespace std;

class Queue {
public:
    int arr[10000];  // 큐를 나타내는 배열
    int frontIdx = 0; // 큐의 앞쪽 인덱스
    int backIdx = 0;  // 큐의 뒤쪽 인덱스

    Queue() {}

    // 큐에 정수 X를 넣는 연산
    void enqueue(int X) {
        arr[backIdx] = X;
        backIdx++;
    }

    // 큐가 비어있는지 확인
    bool isEmpty() {
        return frontIdx == backIdx;
    }

    // 큐에서 가장 앞에 있는 요소를 꺼내고 출력
    int dequeue() {
        if (isEmpty()) {
            return -1;  // 큐가 비어있으면 -1 반환
        }
        int result = arr[frontIdx];
        arr[frontIdx] = 0; // 해당 위치를 비움
        frontIdx++;
        return result;
    }

    // 큐에 있는 요소의 개수를 반환
    int getSize() {
        return backIdx - frontIdx;
    }

    // 큐의 가장 앞에 있는 요소 반환
    int getFront() {
        if (isEmpty()) {
            return -1;  // 큐가 비어있으면 -1 반환
        }
        return arr[frontIdx];
    }

    // 큐의 가장 뒤에 있는 요소 반환
    int getBack() {
        if (isEmpty()) {
            return -1;  // 큐가 비어있으면 -1 반환
        }
        return arr[backIdx - 1];
    }
};

int main() {
    int N; // 명령의 수
    cin >> N;

    Queue q; // 큐 객체 생성

    while (N--) {
        string command;  // 명령어
        cin >> command;

        if (command == "push") {
            int value;  // 넣을 값
            cin >> value;
            q.enqueue(value);
        }
        else if (command == "pop") {
            cout << q.dequeue() << '\n';
        }
        else if (command == "size") {
            cout << q.getSize() << '\n';
        }
        else if (command == "empty") {
            cout << q.isEmpty() << '\n';
        }
        else if (command == "front") {
            cout << q.getFront() << '\n';
        }
        else if (command == "back") {
            cout << q.getBack() << '\n';
        }
    }

    return 0;
}
