#include <iostream>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    int price = 700;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'o') {
            price += 100;
        }
    }

    cout << price << endl;
    return 0;
}