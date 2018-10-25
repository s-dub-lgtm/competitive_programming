#include <iostream>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    bool a = false, b = false, c = false;
    for (int i = 0; i < 3; ++i) {
        if (S[i] == 'a') a = true;
        if (S[i] == 'b') b = true;
        if (S[i] == 'c') c = true;
    }

    if (a && b && c) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}