#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dodo, suyeon;
    deque<int> ground_dodo, ground_suyeon;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dodo.push_front(a);
        suyeon.push_front(b);
    }

    bool turn = true; // true: dodo, false: suyeon

    for (int i = 0; i < m; i++) {
        if (turn) {
            ground_dodo.push_front(dodo.front());
            dodo.pop_front();
        } else {
            ground_suyeon.push_front(suyeon.front());
            suyeon.pop_front();
        }

        // 게임 종료 조건
        if (dodo.empty()) {
            cout << "su" << endl;
            return 0;
        }
        if (suyeon.empty()) {
            cout << "do" << endl;
            return 0;
        }

        // 종 치는 조건
        int top_dodo = ground_dodo.empty() ? 0 : ground_dodo.front();
        int top_suyeon = ground_suyeon.empty() ? 0 : ground_suyeon.front();

        if (top_dodo + top_suyeon == 5) {
            // 수연이 종침
            while (!ground_suyeon.empty()) {
                suyeon.push_back(ground_suyeon.back());
                ground_suyeon.pop_back();
            }
            while (!ground_dodo.empty()) {
                suyeon.push_back(ground_dodo.back());
                ground_dodo.pop_back();
            }
        } else if (top_dodo == 5 || top_suyeon == 5) {
            // 도도가 종침
            while (!ground_dodo.empty()) {
                dodo.push_back(ground_dodo.back());
                ground_dodo.pop_back();
            }
            while (!ground_suyeon.empty()) {
                dodo.push_back(ground_suyeon.back());
                ground_suyeon.pop_back();
            }
        }

        turn = !turn;
    }

    if (dodo.size() > suyeon.size()) cout << "do" << endl;
    else if (dodo.size() < suyeon.size()) cout << "su" << endl;
    else cout << "dosu" << endl;

    return 0;
}
