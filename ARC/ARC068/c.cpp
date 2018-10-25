#include <iostream>

using namespace std;

// 入力
long long x;

int main(void) {
    cin >> x;

    long long cnt;
    cnt = x / 11 * 2;
    long long rem = x % 11;
    if (rem > 6) {
        cnt += 2;
    } else if (rem > 0) {
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}