#include <iostream>

using namespace std;

int main(void) {
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K >> S >> T;

    int total = A * S + B * T;
    if (S + T >= K) {
        total -= (S + T) * C;
    }

    cout << total << endl;
    return 0;
}