#include <iostream>
#include <string>

using namespace std;

// 入力
string s;

int main(void) {
    cin >> s;

    bool success = true;
    while (s.length() != 0) {
//        cout << s << endl;
        if (s.substr(s.length() - 5) == "dream") {
            s = s.substr(0, s.length() - 5);
            continue;
        }
        if (s.substr(s.length() - 5) == "erase") {
            s = s.substr(0, s.length() - 5);
            continue;
        }
        if (s.substr(s.length() - 6) == "eraser") {
            s = s.substr(0, s.length() - 6);
            continue;
        }
        if (s.substr(s.length() - 7) == "dreamer") {
            s = s.substr(0, s.length() - 7);
            continue;
        }
        success = false;
        break;
    }

    if (success) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}