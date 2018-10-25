#include <iostream>

using namespace std;

#define MAX_N 1000

// 入力
int n;

long long divisorNum = 1;
long long cnt[MAX_N + 1];
long long mod = 1e9 + 7;

int main(void) {
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        for (int j = i, k = 2; j > 1;) {
            if (j % k == 0) {
                j /= k;
                cnt[k]++;
            } else {
                k++;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        divisorNum = divisorNum * (cnt[i] + 1) % mod;
    }

    cout << divisorNum << endl;
    return 0;
}