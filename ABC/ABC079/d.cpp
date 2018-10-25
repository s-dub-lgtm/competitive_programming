#include <iostream>

using namespace std;

int c[10][10];
int H, W, A, ans;

int main(void) {
    cin >> H >> W;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> c[i][j];
        }
    }

    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A;
            if (A >= 0) {
                ans += c[A][1];
            }
        }
    }

    cout << ans << endl;
    return 0;
}