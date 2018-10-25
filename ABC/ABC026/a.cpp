#include <iostream>

using namespace std;

int main(void) {
    int A;
    cin >> A;

    if (A % 2 == 1) {
        cout << (A / 2 + 1) * (A / 2) << endl;
    } else {
        cout << (A / 2) * (A / 2) << endl;
    }
    return 0;
}