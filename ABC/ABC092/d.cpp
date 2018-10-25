#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int l = max(a, b);
    int height;
    if (l % 50 == 0) {
        height = (l / 50) * 2;
    } else {
        height = (l / 50 + 1) * 2;
    }
    int width = 100;
    char c[height][width];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (height % 4 == 0 || height % 4 == 1) {
                if (j % 2 == 0) {
                    c[i][j] = '#';
                } else {
                    c[i][j] = '.';
                }
            } else {
                if (j % 2 == 0) {
                    c[i][j] = '.';
                } else {
                    c[i][j] = '#';
                }
            }
        }
    }

//    if (a != b) {
    if (a > b) {
        int dif = a - b;
        for (int i = 0; i < dif; ++i) {
            if (i % 4 == 0 || i % 4 == 1) {
                c[][2 * i + 1] = '#';
            }
        }
    } else {
        int dif = b - a;
        for (int i = 0; i < dif; ++i) {
            c[0][2 * i + 2] = '.';
        }
    }
//    }

    cout << "2 " << 2 * l << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2 * l; ++j) {
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}