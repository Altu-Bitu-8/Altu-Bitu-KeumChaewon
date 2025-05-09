#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> cards;

bool binary_search(int num) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (cards[mid] == num) return true;
        if (cards[mid] < num) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    cin >> n;
    cards.resize(n);
    for (int i = 0; i < n; ++i) cin >> cards[i];
    sort(cards.begin(), cards.end());

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        cout << binary_search(num) << ' ';
    }
    cout << endl;
    return 0;
}
