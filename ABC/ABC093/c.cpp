#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N[3];
    for (int i = 0; i < 3; ++i) {
        cin >> N[i];
    }

    sort(N, N + 3);

    int d1 = N[2] - N[0];
    int d2 = N[2] - N[1];

    int ans;
    if ((d1 - d2) % 2 == 0) {
        ans = (d1 - d2) / 2 + d2;
    } else {
        N[0]++, N[2]++;
        d1 = N[2] - N[0];
        d2 = N[2] - N[1];
        ans = (d1 - d2) / 2 + d2 + 1;
    }
    cout << ans << endl;
    return 0;
}