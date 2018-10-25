#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    long long H, W;
    cin >> H >> W;

    long long ans = 100001;
    long long s[3];

    for (long long i = 1; i < H; ++i) {
        s[0] = i * W;
        s[1] = (H - i) * (W / 2);
        s[2] = (H - i) * (W - (W / 2));
        sort(s, s + 3);
        ans = min(ans, s[2] - s[0]);
    }

    for (long long i = 1; i < W; ++i) {
        s[0] = i * H;
        s[1] = (W - i) * (H / 2);
        s[2] = (W - i) * (H - (H / 2));
        sort(s, s + 3);
        ans = min(ans, s[2] - s[0]);
    }

    for (long long i = 1; i < H; ++i) {
        s[0] = i * W;
        s[1] = ((H - i) / 2) * W;
        s[2] = ((H - i) - ((H - i) / 2)) * W;
        sort(s, s + 3);
        ans = min(ans, s[2] - s[0]);
    }

    for (long long i = 1; i < W; ++i) {
        s[0] = i * H;
        s[1] = ((W - i) / 2) * H;
        s[2] = ((W - i) - ((W - i) / 2)) * H;
        sort(s, s + 3);
        ans = min(ans, s[2] - s[0]);
    }

    cout << ans << endl;
    return 0;
}