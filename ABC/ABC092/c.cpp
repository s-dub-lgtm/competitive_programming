#include <iostream>

using namespace std;

//int cost[5001][5001];

int main(void) {
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = 0;

//    for (int i = -5000; i <= 5000; ++i) {
//        for (int j = -5000; j <= 5000; ++j) {
//            cost[i][j] = abs(i - j);
//        }
//    }

    long long total = 0;
    for (int i = 0; i < n + 1; ++i) {
        total += abs(a[i + 1] - a[i]);
    }

    for (int i = 0; i < n; ++i) {
        long long ans;
        ans = total - abs(a[i + 1] - a[i]) - abs(a[i + 2] - a[i + 1]) + abs(a[i + 2] - a[i]);
        cout << ans << endl;
    }
    return 0;
}