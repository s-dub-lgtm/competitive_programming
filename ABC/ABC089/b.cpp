#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    bool y = false;
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'Y') {
            y = true;
        }
    }

    if (y) {
        cout << "Four" << endl;
    } else {
        cout << "Three" << endl;
    }
    return 0;
}