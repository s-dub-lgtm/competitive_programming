#include <iostream>

using namespace std;

int main(void) {
    string S, T;
    cin >> S >> T;

    bool win = true;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == '@') {
            if (T[i] != '@' && T[i] != 'a' && T[i] != 't' && T[i] != 'c' && T[i] != 'o' && T[i] != 'd' && T[i] != 'e' &&
                T[i] != 'r') {
                win = false;
                break;
            }
        } else if (T[i] == '@') {
            if (S[i] != '@' && S[i] != 'a' && S[i] != 't' && S[i] != 'c' && S[i] != 'o' && S[i] != 'd' && S[i] != 'e' &&
                S[i] != 'r') {
                win = false;
                break;
            }
        } else if (S[i] != T[i]) {
            win = false;
        }
    }

    if (win) cout << "You can win" << endl;
    else cout << "You will lose" << endl;
    return 0;
}