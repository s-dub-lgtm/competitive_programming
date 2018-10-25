#include <iostream>

using namespace std;

int main(void) {
    string A, B;
    cin >> A >> B;

    if (A.length() > B.length()) cout << A << endl;
    else cout << B << endl;
    return 0;
}