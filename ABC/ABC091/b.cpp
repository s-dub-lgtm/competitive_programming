#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int m;
    cin >> m;
    string t[m];
    for (int j = 0; j < m; ++j) {
        cin >> t[j];
    }

    int maxyen = 0;
    for (int i = 0; i < n; ++i) {
        string speak = s[i];
        int yen = 0;
        for (int j = 0; j < n; ++j) {
            if (speak == s[j]) {
                yen++;
            }
        }
        for (int k = 0; k < m; ++k) {
            if (speak == t[k]) {
                yen--;
            }
        }
        maxyen = max(maxyen, yen);
    }

    cout << maxyen << endl;
    return 0;
}