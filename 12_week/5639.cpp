#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

void postorder(int start, int end) {
    if (start > end) return;

    int root = preorder[start];
    int idx = start + 1;

    while (idx <= end && preorder[idx] < root)
        idx++;

    postorder(start + 1, idx - 1); // left
    postorder(idx, end);          // right
    cout << root << "\n";         // root
}

int main() {
    int num;
    while (cin >> num) {
        preorder.push_back(num);
    }

    postorder(0, preorder.size() - 1);
    return 0;
}
