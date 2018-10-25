#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> memo;

int main(void) {
    string s;
    int K;
    cin >> s >> K;

//    vector<string> memo;
    int cnt = 0;


    for (int i = 0; i < 26; ++i) {
        char search = char('a' + i);
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == search) {
                for (int k = 1; k <= s.length() - j; ++k) {
                    string sub = s.substr(j, k);
                    memo.push_back(sub);
//                    cnt++;
//                    if (cnt > 100) break;
                    if (k == 5) break;
                }
            }
//            if (cnt > 500) break;
        }
//        if (cnt >= 4) break;
    }
//    for (int i = 0; i < memo.size(); ++i) {
//        cout << memo[i] << endl;
//    }


    sort(memo.begin(), memo.end());
//    cout << "sorted" << endl;
//    for (int i = 0; i < memo.size(); ++i) {
//        cout << memo[i] << endl;
//    }

    unique(memo.begin(), memo.end());
//    cout << "uniqued" << endl;
//    for (int i = 0; i < memo.size(); ++i) {
//        cout << memo[i] << endl;
//    }

    cout << memo[K - 1] << endl;

//    cout << memo[K] << endl;
//    string ans;
//    if (K == memo.size()) {
//        ans = memo[K - 1];
//    } else {
//        cnt = 0;
//        for (int i = 1; i < memo.size(); ++i) {
//            if (memo[i - 1] != memo[i]) {
//                cnt++;
//                if (cnt == K) {
//                    ans = memo[i - 1];
//                    break;
//                }
//            }
//        }
//    }
//
//    cout << ans << endl;
    return 0;
}