#include <iostream>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    if ('a' <= S[0] && S[0] <= 'z') {
        S[0] = (char) (S[0] + 'A' - 'a');
    }

    for (int i = 1; i < S.length(); ++i) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            S[i] = (char) (S[i] - 'A' + 'a');
        }
    }

    cout << S << endl;
    return 0;
}