#include <iostream>

using namespace std;

// 入力
long long X, Y;

int main(void) {
    cin >> X >> Y;

    long long cnt = 0;
    while (X <= Y) {
        X *= 2;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}