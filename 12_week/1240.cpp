#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[1001];
bool visited[1001];
int answer = 0;

void dfs(int current, int target, int distance) {
    if (current == target) {
        answer = distance;
        return;
    }

    visited[current] = true;
    for (int i = 0; i < tree[current].size(); ++i) {
        int next = tree[current][i].first;
        int weight = tree[current][i].second;
        if (!visited[next])
            dfs(next, target, distance + weight);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        memset(visited, false, sizeof(visited));
        answer = 0;
        dfs(u, v, 0);
        cout << answer << '\n';
    }

    return 0;
}
