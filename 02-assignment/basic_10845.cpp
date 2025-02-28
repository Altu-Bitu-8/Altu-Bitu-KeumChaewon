#include<iostream>
using namespace std;
 
class Queue {
public:
	int queue[10000];
	// 큐에 포함되어있는 내용은 begin~end-1까지임
	int begin = 0;
	int end = 0;
 
	Queue() {}
 
	void push(int X) { // 정수 X를 큐에 넣는 연산
		queue[end] = X;
		end += 1;
	}
 
	bool empty() { // 큐가 비어있으면 1, 아니면 0 출력
		if (end == begin)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
 
	int pop() { // 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력
		// 큐에 들어있는 정수가 없는 경우에 -1 출력
		if (empty())
		{
			return -1;
		}
		int r = queue[begin];
		queue[begin] = 0;
		begin += 1;
		return r;
	}
 
	int size() { // 큐에 들어있는 정수의 개수를 출력
		return end - begin; // 큐에 포함되어있는 내용은 begin~end-1까지임
	}
 
 
	int front() { // 큐의 가장 앞에 있는 정수 출력.
		// 큐에 들어있는 정수가 없는 경우에 -1 출력
		if (empty())
		{
			return -1;
		}
		return queue[begin];
	}
 
	int back() { // 큐의 가장 뒤에 있는 정수 출력.
		// 큐에 들어있는 정수가 없는 경우에 -1 출력
		if (empty())
		{
			return -1;
		}
		return queue[end - 1];
	}
};
 
int main() {
	int N; // 주어지는 명령의 수
	cin >> N;
 
	Queue q;
 
	while (N--) {
 
		string cmd; // 명령어
		cin >> cmd;
 
		if (cmd == "push")
		{
			int input; // 넣을 입력값
			cin >> input;
			q.push(input);
		}
		else if (cmd == "pop")
		{
			cout << q.pop() << '\n';
		}
		else if (cmd == "size")
		{
			cout << q.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (cmd == "front") {
			cout << q.front() << '\n';
		}
		else if (cmd == "back")
		{
			cout << q.back() << '\n';
		}
	}
 
	return 0;
}