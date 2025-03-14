#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;

vector<bool> sieve(MAX, true);

void generatePrimes() {
    sieve[0] = sieve[1] = false; // 0과 1은 소수가 아님
    for (int i = 2; i * i < MAX; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j < MAX; j += i) {
                sieve[j] = false; // i의 배수는 소수가 아님
            }
        }
    }
}

int main() {
    generatePrimes(); // 소수 배열 생성

    int n;
    while (cin >> n && n != 0) { // n이 0이면 종료
        bool found = false;
        for (int i = 2; i <= n / 2; ++i) {
            if (sieve[i] && sieve[n - i]) { // i와 n-i가 소수이면
                cout << n << " = " << i << " + " << n - i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }

    return 0;
}
