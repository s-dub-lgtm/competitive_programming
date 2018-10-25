#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    int Q;
    cin >> Q;
    long double A[Q], B[Q];
    for (int i = 0; i < Q; ++i) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < Q; ++i) {
        if ((A[i] == 1 && B[i] == 1) || (A[i] == 1 && B[i] == 2) || (A[i] == 2 && B[i] == 1)) {
            cout << 0 << endl;
            continue;
        } else if ((A[i] == 1 && B[i] == 3) || (A[i] == 3 && B[i] == 1)) {
            cout << 1 << endl;
            continue;
        }
        long double C = A[i] * B[i] - 1;
        long long ans;
        if (sqrtl(C) == (long long) (sqrtl(C))) {
            ans = ((long long) (sqrtl(C)) - 1) * 2 + 1;
        } else {
            ans = (long long) (sqrtl(C)) * 2;
        }
        if (A[i] != B[i]) ans--;
        if (abs(A[i] - B[i]) == 1) {
            ans--;
        } else {
            long double D = C - 1;
            if (sqrtl(D) == (long long) (sqrtl(D))) ans--;
        }
        cout << ans << endl;
    }
    return 0;
}