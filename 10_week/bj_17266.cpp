#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> lights;

bool isPossible(int height) {
    int last_covered = 0;
    for (int light : lights) {
        if (light - height > last_covered) 
            return false;
        last_covered = light + height;
    }
    return last_covered >= n;
}

int main() {
    cin >> n >> m;
    lights.resize(m);
    for (int i = 0; i < m; ++i) 
        cin >> lights[i];
    
    sort(lights.begin(), lights.end());

    int left = 1, right = n, result = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
