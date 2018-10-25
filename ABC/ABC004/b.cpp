#include <iostream>

using namespace std;

int main(void) {
    char c[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> c[i][j];
        }
    }

    char ans[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ans[i][j] = c[3 - i][3 - j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j != 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}