#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[101];
bool visited[101];
int cnt = 0;

void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << cnt << '\n';
    return 0;
}
