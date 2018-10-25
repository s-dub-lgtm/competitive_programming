#include <iostream>

using namespace std;

int main(void) {
    int c[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> c[i][j];
        }
    }

    int c_1 = 0, c_2 = 0, c_3 = 0;
    for (int i = 0; i < 3; ++i) {
        c_1 += c[i][0];
        c_2 += c[i][1];
        c_3 += c[i][2];
    }

    bool correct = false;
    for (int i = -100; i <= 100; ++i) {
        for (int j = -100; j <= 100; ++j) {
            for (int k = -100; k <= 100; ++k) {
                if ((i + j + k - c_1) % 3 == 0) {
                    if ((i + j + k - c_2) % 3 == 0) {
                        if ((i + j + k - c_3) % 3 == 0) {
                            correct = true;
                        }
                    }
                }
            }
        }
    }

//    cout << c_1 << " " << c_2 << " " << c_3 << endl;
    if (correct) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}