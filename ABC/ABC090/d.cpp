#include <iostream>

using namespace std;

#define MAX_N 100000

long long mem[MAX_N + 1];

int main(void) {
    int n, k;
    cin >> n >> k;

    for (int i = k + 1; i <= n; ++i) {
        mem[i - 1] += n - i + 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            if (i % j >= k) {
                mem[i % j]++;
            }
        }
    }

    long long sum = 0;
    for (int i = k; i < n; ++i) {
        sum += mem[i];
    }

    cout << sum << endl;
    return 0;
}