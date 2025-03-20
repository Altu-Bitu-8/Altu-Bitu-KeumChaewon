#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;

vector<bool> sieve(MAX, true);

void generatePrimes() {
    sieve[0] = sieve[1] = false; // 소수x (0,1)
    for (int i = 2; i * i < MAX; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j < MAX; j += i) {
                sieve[j] = false; // 소수x (i의 배수수)
            }
        }
    }
}

int main() {
    generatePrimes(); // 소수 배열

    int n;
    while (cin >> n && n != 0) { // n==0 종료
        bool found = false;
        for (int i = 2; i <= n / 2; ++i) {
            if (sieve[i] && sieve[n - i]) { // if) i와 n-i가 소수수
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
