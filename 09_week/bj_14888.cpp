#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums;
int ops[4]; // +, -, *, /
int max_val = -1e9;
int min_val = 1e9;

void dfs(int idx, int current) {
    if (idx == n) {
        max_val = max(max_val, current);
        min_val = min(min_val, current);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (ops[i] > 0) {
            ops[i]--;
            if (i == 0) dfs(idx + 1, current + nums[idx]);
            else if (i == 1) dfs(idx + 1, current - nums[idx]);
            else if (i == 2) dfs(idx + 1, current * nums[idx]);
            else if (i == 3) dfs(idx + 1, current / nums[idx]);
            ops[i]++;
        }
    }
}

int main() {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < 4; i++) cin >> ops[i];

    dfs(1, nums[0]);
    cout << max_val << "\n" << min_val << "\n";
    return 0;
}
