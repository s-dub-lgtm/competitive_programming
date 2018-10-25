#include <iostream>

using namespace std;

int N;
int F[100][10];
int P[100][11];


int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> F[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> P[i][j];
        }
    }

    int res = -(1 << 30);
    for (int b = 1; b < (1 << 10); b++) {
        int cc = 0;
        for (int i = 0; i < N; ++i) {
            int c = 0;
            for (int j = 0; j < 10; ++j) {
                if ((b >> j & 1) && F[i][j]) {
                    c++;
                }
            }
            cc += P[i][c];
        }
        if (res < cc) res = cc;
    }

    cout << res << endl;
    return 0;
}