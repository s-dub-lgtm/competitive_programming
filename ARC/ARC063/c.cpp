#include <iostream>

using namespace std;

// 入力
string s;

int main(void) {
    cin >> s;

    int change = 0;
    char point = s[0];
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != point) {
            change++;
            point = s[i];
        }
    }

    cout << change << endl;
    return 0;
}