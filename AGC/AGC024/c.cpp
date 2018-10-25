#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    long long A[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    if (A[1] != 0) { // X1は0以外にならない
        cout << -1 << endl;
        return 0;
    }

    long long total = 0;
//    long long cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (A[i + 1] - A[i] >= 2) {
            cout << -1 << endl;
            return 0;
        }
        if (A[i] >= A[i + 1]) {
            total += A[i];
        }
//        if(A[i]+1==A[i+1]){
//
//        }
        if (i == N - 1) {
            total += A[N];
        }
    }

    cout << total << endl;
    return 0;
}