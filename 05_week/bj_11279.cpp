#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEmpty(vector<int> &heap) {
    return heap.size() == 1;
}

void push( int x, vector<int> &heap ) {
    int idx = heap.size();

    // 삽입
    heap.push_back(x);

    while ( idx >1 && heap[idx] > heap[idx/2] ) {
        // 자식이 부모보다 값이 큰 경우 위치를 바꿈
        // idx는 1보다 큰 경우만 고려해야 해서 조건을 추가
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }

} 

void pop( vector<int> &heap ) {
    // 마지막 원소를 루트 원소로
    int item = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();  //사이즈도 줄고, 마지막 원소가 없어짐 but 시간복잡도상 많은 시간이 걸리고, 웬만한 경우는 stack을 사용

    int idx = 1;

    int parent = 1;
    int child = 2;
    int size = heap.size();

    
    while ( child < size ) {
        // 1. 왼쪽 & 오른쪽 비교
        if ( child + 1 < size && heap[child] < heap[child + 1]) {
            child++;
        }
        
        // 2. 더 큰 자식이 나(부모)보다 클 때 바꿈
        if (heap[child] > heap[parent]) {
            swap(heap[child], heap[parent]);
            parent = child;
            child = parent * 2;
        } else{
            return item;
        }
    }

    
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> heap(1,0);  // 첫 번째 인덱스를 사용하지 않을 것이기에 초기 상태

    while(n--);{
        cin >> x;
        switch (x) {
            case 0:
                // 삭제

                break;

            default:// 삽입
                push()
                break;
        }
    }

    return 0;
}