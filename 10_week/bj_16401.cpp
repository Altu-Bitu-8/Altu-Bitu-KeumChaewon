#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<int> snacks;

bool canDistribute(int length) {
    int count = 0;
    for (int snack : snacks) 
        count += snack / length;
    return count >= m;
}

int main() {
    cin >> m >> n;
    snacks.resize(n);
    for (int i = 0; i < n; ++i) 
        cin >> snacks[i];

    sort(snacks.begin(), snacks.end());

    int left = 1, right = *max_element(snacks.begin(), snacks.end());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canDistribute(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
