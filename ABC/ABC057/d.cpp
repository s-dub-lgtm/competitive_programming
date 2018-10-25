#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 50

// 入力
int N, A, B;
long long v[MAX_N];

long long C[51][51];

void comb_table(int N) {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                C[i][j] = 1LL;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
            }
        }
    }
}

int main(void) {
    cin >> N >> A >> B;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    comb_table(N);
    sort(v, v + N);
    reverse(v, v + N);

    long double max_average = 0.0;
    for (int i = 0; i < A; ++i) {
        max_average += v[i];
    }
    max_average /= A;

    int a_th_val_num = 0, a_th_val_pos = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i] == v[A - 1]) {
            a_th_val_num++;
            if (i < A) {
                a_th_val_pos++;
            }
        }
    }

    long long cnt = 0LL;
    if (a_th_val_pos == A) {
        for (a_th_val_pos = A; a_th_val_pos <= B; ++a_th_val_pos) {
            cnt += C[a_th_val_num][a_th_val_pos];
        }
    } else {
        cnt += C[a_th_val_num][a_th_val_pos];
    }

    cout.precision(20);
    cout << fixed << max_average << endl;
    cout << cnt << endl;
    return 0;
}