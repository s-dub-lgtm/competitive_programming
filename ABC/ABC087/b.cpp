#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    long long cnt = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                if ((500 * i + 100 * j + 50 * k) == x) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}