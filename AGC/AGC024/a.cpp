#include <iostream>

using namespace std;

int main(void) {
    long long A, B, C, K;
    cin >> A >> B >> C >> K;

    if (abs(A - B) > 1000000000000000000) {
        cout << "Unfair" << endl;
    } else if (K % 2 == 0) {
        cout << A - B << endl;
    } else {
        cout << -(A - B) << endl;
    }
    return 0;
}