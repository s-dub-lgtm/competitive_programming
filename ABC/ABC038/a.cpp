#include <iostream>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    if (S[S.length() - 1] == 'T') cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}