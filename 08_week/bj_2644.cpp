#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b, m;
vector<int> graph[101];
bool visited[101];
int dist[101];

int bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == target) return dist[cur];

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> a >> b >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << bfs(a, b) << '\n';
    return 0;
}
