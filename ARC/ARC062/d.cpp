#include <iostream>

using namespace std;

// 入力
string s;

int main(void) {
    cin >> s;

    int p_num = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'p') p_num++;

    }

    int point = s.length() / 2 - p_num;

    cout << point << endl;
    return 0;
}