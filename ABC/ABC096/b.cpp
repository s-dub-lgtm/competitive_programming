#include <iostream>

using namespace std;

long long K;

long long by(long long num) {
    for (int i = 0; i < K; ++i) {
        num = num * 2;
    }
    return num;
}

int main(void) {
    long long A, B, C;
    cin >> A >> B >> C;
    cin >> K;

    long long maxnum;
    long long sum = 0;
    if (A >= B) {
        if (A >= C) {
            maxnum = by(A);
            sum = maxnum + B + C;
        } else if (C >= A) {
            maxnum = by(C);
            sum = maxnum + A + B;
        }
    } else {
        if (B >= C) {
            maxnum = by(B);
            sum = maxnum + A + C;
        } else {
            maxnum = by(C);
            sum = maxnum + A + B;
        }
    }
    cout << sum << endl;
    return 0;
}