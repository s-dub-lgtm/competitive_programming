#include <iostream>

using namespace std;

int H, W, D, A;
int Q, L, R;
int px[90001], py[90001];
int d[90001];

int main(void) {
    cin >> H >> W >> D;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A;
            px[A] = i, py[A] = j;
        }
    }

    for (int i = D + 1; i <= H * W; ++i) {
        d[i] = d[i - D] + abs(px[i] - px[i - D]) + abs(py[i] - py[i - D]);
    }

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> L >> R;
        cout << d[R] - d[L] << endl;
    }
    return 0;
}