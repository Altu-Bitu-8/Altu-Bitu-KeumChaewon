#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;      // 스택 선언
    int N;             // 명령의 개수
    string cmd;        // 명령어
    int num;           // push 명령 시 삽입할 정수
    int output = 0;    // 각 명령에 대한 출력값

    cin >> N;  // 명령의 개수를 입력받음

    for (int i = 0; i < N; i++) {
        cin >> cmd;  // 명령어를 입력받음

        // push 연산
        if (cmd == "push") {
            cin >> num;  // 스택에 넣을 정수 입력
            s.push(num);  // 스택에 값 넣기
        }

        // pop 연산
        else if (cmd == "pop") {
            if (s.empty()) {
                output = -1;  // 스택이 비어있으면 -1 출력
                cout << output << endl;
            }
            else {
                output = s.top();  // 스택의 맨 위 값을 출력
                cout << output << endl;
                s.pop();  // 스택에서 가장 위의 값 제거
            }
        }

        // size 연산
        else if (cmd == "size") {
            cout << s.size() << endl;  // 스택에 들어있는 원소의 개수 출력
        }

        // empty 연산
        else if (cmd == "empty") {
            if (s.empty()) {
                output = 1;  // 스택이 비어있으면 1 출력
                cout << output << endl;
            }
            else {
                output = 0;  // 스택에 원소가 있으면 0 출력
                cout << output << endl;
            }
        }

        // top 연산
        else if (cmd == "top") {
            if (s.empty()) {
                output = -1;  // 스택이 비어있으면 -1 출력
                cout << output << endl;
            }
            else {
                output = s.top();  // 스택의 맨 위 값을 출력
                cout << output << endl;
            }
        }
    }

    return 0;
}
