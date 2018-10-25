#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = a; i <= b; ++i) {
        int tmp = i;
        int rev = 0;
        int rem;
        while (tmp != 0) {
            rem = tmp % 10;
            rev = rev * 10 + rem;
            tmp /= 10;
        }
        if (rev == i) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}