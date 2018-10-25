#include <iostream>

using namespace std;

#define MAX_N 100000

// 入力
int N, M;

const int MOD = 1e9 + 7;

long long mem[MAX_N + 1];

long long fact(long long i) {
    if (i == 1) {
        return 1;
    } else if (mem[i] != 0) {
        return mem[i];
    } else {
        return mem[i] = (i * fact(i - 1)) % MOD;
    }
}

int main(void) {
    cin >> N >> M;

    if (abs(N - M) > 1) {
        cout << "0" << endl;
        return 0;
    } else if (N == M) {
        cout << (fact(N) * fact(M) * 2) % MOD << endl;
    } else {
        cout << (fact(N) * fact(M)) % MOD << endl;
    }

    return 0;
}