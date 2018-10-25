#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_S 10

// 入力
char s[MAX_S];

long long ans = 0;
long long arr[MAX_S] = {1, 11, 112, 1124, 11248, 112496, 1124992, 11249984, 112499968, 1124999936};

int main() {
    cin >> s;

    int le = strlen(s);
    for (int i = 0; i < le; ++i) {
        ans += arr[le - i - 1] * pow(2, i) * (s[i] - '0');
    }

    cout << ans << endl;
    return 0;
}