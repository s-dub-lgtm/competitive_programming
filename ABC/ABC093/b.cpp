#include <iostream>

using namespace std;

int main(void) {
    int A, B, K;
    cin >> A >> B >> K;

    if (abs(A - B) <= K) {
        for (int i = A; i <= B; ++i) {
            cout << i << endl;
        }
    } else {
        for (int i = A; i < A + K; ++i) {
            cout << i << endl;
        }
        for (int i = B - K + 1; i <= B; ++i) {
            if (i > A + K - 1) cout << i << endl;
        }
    }
    return 0;
}