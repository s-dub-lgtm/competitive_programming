#include <iostream>

using namespace std;

#define MAX_N 1000

// 入力
int N;
int T[MAX_N], A[MAX_N];

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> A[i];
    }

    long long vote_t = 1, vote_a = 1;
    for (int i = 0; i < N; ++i) {
        long long n_t, n_a;
        if (vote_t % T[i] == 0) {
            n_t = vote_t / T[i];
        } else {
            n_t = vote_t / T[i] + 1;
        }
        if (vote_a % A[i] == 0) {
            n_a = vote_a / A[i];
        } else {
            n_a = vote_a / A[i] + 1;
        }
        long long n = max(n_t, n_a);
//        cout << "n_t" << n_t << " n_a" << n_a << endl;
//        cout << "n: " << n << endl;
        vote_t = T[i] * n;
        vote_a = A[i] * n;
//        cout << vote_t << " " << vote_a << endl;
    }

    cout << vote_t + vote_a << endl;
    return 0;
}