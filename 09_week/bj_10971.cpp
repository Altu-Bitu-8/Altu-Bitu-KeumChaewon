#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> w(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    int answer = 1e9;

    do {
        int cost = 0;
        bool valid = true;
        for (int i = 0; i < n - 1; i++) {
            if (w[perm[i]][perm[i + 1]] == 0) {
                valid = false;
                break;
            }
            cost += w[perm[i]][perm[i + 1]];
        }
        if (valid && w[perm[n - 1]][perm[0]] != 0) {
            cost += w[perm[n - 1]][perm[0]];
            answer = min(answer, cost);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << answer << "\n";
    return 0;
}
