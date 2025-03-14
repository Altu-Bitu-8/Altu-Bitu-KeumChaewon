#include <iostream>

using namespace std;

int find_min_year(int e, int s, int m) {
    int year = 1;
    int e_now = 1, s_now = 1, m_now = 1;

    while (true) {
        if (e_now == e && s_now == s && m_now == m) {
            return year;
        }

        e_now = (e_now % 15) + 1;
        s_now = (s_now % 28) + 1;
        m_now = (m_now % 19) + 1;
        year++;
    }
}

int main() {
    int earth, sun, moon;
    cin >> earth >> sun >> moon;

    cout << find_min_year(earth, sun, moon) << endl;

    return 0;
}
