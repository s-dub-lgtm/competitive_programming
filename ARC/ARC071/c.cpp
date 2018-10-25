#include <iostream>

using namespace std;

#define MAX_N 50
#define MAX_S 50
// 入力
int n;
string S[MAX_N];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    int mem[26] = {};
    for (int l = 0; l < 26; ++l) {
        mem[l] = MAX_S;
    }

    for (int i = 0; i < n; ++i) {
        int cnt[26] = {};
        for (int j = 0; j < S[i].length(); ++j) {
            cnt[S[i][j] - 'a']++;
        }
//        for (int l = 0; l < 26; ++l) {
//            cout << cnt[l] << " ";
//        }
//        cout << endl;
        for (int l = 0; l < 26; ++l) {
            mem[l] = min(mem[l], cnt[l]);
        }
    }

    for (int l = 0; l < 26; ++l) {
        while (mem[l] > 0) {
            cout << (char) ('a' + l);
            mem[l]--;
        }
    }
    cout << endl;
    return 0;
}