#include <iostream>

using namespace std;

int main(void) {
    string W;
    cin >> W;

    string ans = "";
    for (int i = 0; i < W.length(); ++i) {
        if (W[i] != 'a' && W[i] != 'i' && W[i] != 'u' && W[i] != 'e' && W[i] != 'o') {
            ans += W[i];
        }
    }

    cout << ans << endl;
    return 0;
}