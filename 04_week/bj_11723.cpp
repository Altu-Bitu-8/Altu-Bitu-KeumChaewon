#include <iostream>
#include <string>

using namespace std;

const int MAX_BIT = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_operations;
    cin >> num_operations;

    int bit_set = 0;

    while (num_operations--) {
        string operation;
        int num;

        cin >> operation;
        if (operation == "add") {
            cin >> num;
            bit_set |= (1 << (num - 1));
        } 
        else if (operation == "remove") {
            cin >> num;
            bit_set &= ~(1 << (num - 1));
        } 
        else if (operation == "check") {
            cin >> num;
            cout << ((bit_set & (1 << (num - 1))) ? 1 : 0) << '\n';
        } 
        else if (operation == "toggle") {
            cin >> num;
            bit_set ^= (1 << (num - 1));
        } 
        else if (operation == "all") {
            bit_set = (1 << MAX_BIT) - 1;
        } 
        else if (operation == "empty") {
            bit_set = 0;
        }
    }

    return 0;
}
