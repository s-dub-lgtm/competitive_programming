#include <iostream>

using namespace std;

int main(void) {
    long long n, m;
    cin >> n >> m;
    if (n >= 3 && m >= 3) {
        cout << (n - 2) * (m - 2) << endl;
    } else if (n == 2 || m == 2) {
        cout << 0 << endl;
    } else if (n == 1 && m == 1) {
        cout << 1 << endl;
    } else if (n == 1 && m == 3) {
        cout << 1 << endl;
    } else if (n == 3 && m == 1) {
        cout << 1 << endl;
    } else if (n == 3 && m == 3) {
        cout << 1 << endl;
    } else if (n >= 3) {
        cout << (n - 2) << endl;
    } else if (m >= 3) {
        cout << m - 2 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}