#include <iostream>

using namespace std;

int main(void) {
    double A, B, C, D;
    cin >> A >> B >> C >> D;

    if (B / A == D / C) cout << "DRAW" << endl;
    else if (B / A > D / C) cout << "TAKAHASHI" << endl;
    else cout << "AOKI" << endl;
    return 0;
}