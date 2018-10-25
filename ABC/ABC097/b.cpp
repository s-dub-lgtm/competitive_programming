#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long long X;
    cin >> X;

    long long ans = 1;
    for (int i = 1; i < X; ++i) {
        for (int j = 2; j < X; ++j) {
            long long beki = pow(i, j);
            if (beki <= X) {
                ans = max(ans, beki);
            }
        }
    }

    cout << ans << endl;
    return 0;
}