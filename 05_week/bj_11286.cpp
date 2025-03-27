#include <iostream>
#include <queue>

using namespace std;

//아래와 같이 넣으면 최대 힙이 나옴 => 더 작을 때 true가 되고 swap을 해야되니까..?
struct cmp {
    bool operator()(const int &x1, const int &x2) {
        if (abs(x1) != abs(x2)) {
            return abs(x2) < abs(x1);
        }
        return x1 < x2;
        // x1 : child, x2 : parent

    }
};

