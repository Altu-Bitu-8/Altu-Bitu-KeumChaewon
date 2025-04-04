#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long x = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (x % a[i] == 0) continue;
        x = ((x / a[i]) + 1) * a[i];
    }

    cout << x << "\n";
    return 0;
}
