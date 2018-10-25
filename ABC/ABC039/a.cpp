#include <iostream>

using namespace std;

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    cout << (A * B + B * C + C * A) * 2 << endl;
    return 0;
}