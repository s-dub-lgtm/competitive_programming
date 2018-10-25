#include <iostream>

using namespace std;

// 入力
long long N, M;

int main(void) {
    cin >> N >> M;

    long long num;
    if (2 * N > M) {
        num = M / 2;
    } else {
        num = N;
        M = M - 2 * N;
        num += M / 4;
    }

    cout << num << endl;
    return 0;
}