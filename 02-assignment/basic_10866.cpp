#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> deq;  // 덱을 나타내는 deque
    int N;
    
    cin >> N;
    
    while (N--) {
        string command;
        cin >> command;
        
        if (command == "push_front") {
            int value;
            cin >> value;
            deq.push_front(value);  // 덱의 앞에 삽입
        }
        
        else if (command == "push_back") {
            int value;
            cin >> value;
            deq.push_back(value);  // 덱의 뒤에 삽입
        }
        
        else if (command == "pop_front") {
            if (!deq.empty()) {
                cout << deq.front() << "\n";  // 덱의 앞에서 값을 꺼냄
                deq.pop_front();  // 덱의 앞에서 값을 제거
            }
            else {
                cout << "-1\n";  // 덱이 비어있으면 -1 출력
            }
        }
        
        else if (command == "pop_back") {
            if (!deq.empty()) {
                cout << deq.back() << "\n";  // 덱의 뒤에서 값을 꺼냄
                deq.pop_back();  // 덱의 뒤에서 값을 제거
            }
            else {
                cout << "-1\n";  // 덱이 비어있으면 -1 출력
            }
        }
        
        else if (command == "size") {
            cout << deq.size() << "\n";  // 덱에 들어있는 요소의 개수 출력
        }
        
        else if (command == "empty") {
            cout << deq.empty() << "\n";  // 덱이 비어있는지 여부 출력
        }
        
        else if (command == "front") {
            if (!deq.empty()) {
                cout << deq.front() << "\n";  // 덱의 앞에 있는 값 출력
            }
            else {
                cout << "-1\n";  // 덱이 비어있으면 -1 출력
            }
        }
        
        else if (command == "back") {
            if (!deq.empty()) {
                cout << deq.back() << "\n";  // 덱의 뒤에 있는 값 출력
            }
            else {
                cout << "-1\n";  // 덱이 비어있으면 -1 출력
            }
        }
    }

    return 0;
}
