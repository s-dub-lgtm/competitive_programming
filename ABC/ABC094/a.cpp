#include <iostream>

using namespace std;

int main(void) {
    int A, B, X;
    cin >> A >> B >> X;

    if (A <= X && X <= (A + B)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}