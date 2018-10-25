#include <iostream>

using namespace std;

int main(void) {
    int H, W;
    cin >> H >> W;
    char s[H][W];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> s[i][j];
        }
    }

    bool success = true;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (s[i][j] == '#') {
                bool can = false;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if (0 <= nx && nx < W && 0 <= ny && ny < H && s[ny][nx] == '#') {
                        can = true;
                    }
                }
                if (!can) {
                    success = false;
                }
            }
        }
    }

    if (success) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}