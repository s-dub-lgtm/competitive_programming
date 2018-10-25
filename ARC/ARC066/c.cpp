#include <iostream>

using namespace std;

#define MAX_N 100000

// 入力
int N;
int A[MAX_N + 1];

int cnt[MAX_N];
long long kind = 1;

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; ++i) {
        cnt[A[i]]++;
    }

    bool exist = true;
    if (N % 2 == 0) {
        for (int j = 1; j < N; ++j) {
            if (j % 2 == 1) {
                kind = kind * 2 % 1000000007;
                if (cnt[j] != 2) {
                    exist = false;
                }
            }
        }
    } else {
        if (cnt[0] != 1) exist = false;
        for (int j = 2; j < N; ++j) {
            if (j % 2 == 0) {
                kind = kind * 2 % 1000000007;
                if (cnt[j] != 2) {
                    exist = false;
                }
            }
        }
    }

    if (exist) {
        cout << kind << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}