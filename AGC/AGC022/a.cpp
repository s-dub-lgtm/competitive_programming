#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    bool used[26];
    for (int i = 0; i < 26; ++i) {
        used[i] = false;
    }

    for (int i = 0; i < s.length(); ++i) {
        used[s[i] - 'a'] = true;
    }

    bool all_used = true;
    for (int i = 0; i < 26; ++i) {
        if (used[i] == false) {
            all_used = false;
            break;
        }
    }

//    for (int i = 0; i < 26; ++i) {
//        cout << used[i] << endl;
//    }
//    cout << all_used << endl;

    string ans;
    if (all_used) {
        if (s == "zyxwvutsrqponmlkjihgfedcba") {
            ans = "-1";
            cout << ans << endl;
        } else {
            int div_pos;
            bool exist[26];
            for (int i = 0; i < 26; ++i) {
                exist[i] = false;
            }
            for (int i = s.length() - 1; i > 0; --i) {
                exist[s[i] - 'a'] = true;
                if (s[i - 1] < s[i]) {
                    div_pos = i;
                    break;
                }
            }
            if (s[div_pos] == 'z') {
                s[div_pos - 1] = (char) (s[div_pos - 1] + 1);
                for (int i = 0; i < div_pos; ++i) {
                    cout << s[i];
                }
                cout << endl;
            } else {
                for (int i = 0; i < div_pos; ++i) {
                    cout << s[i];
                }
                for (int i = 0; i < 26; ++i) {
                    if (exist[i] == true) {
                        cout << (char) ('a' + i);
                    }
                }
                cout << endl;
            }
        }
    } else {
        string first;
        for (int i = 0; i < 26; ++i) {
            if (used[i] == false) {
//                first = to_string('a' + i);
                first = (char) ('a' + i);
                break;
            }
        }
        cout << s << first << endl;
    }
//    cout << ans << endl;
    return 0;
}