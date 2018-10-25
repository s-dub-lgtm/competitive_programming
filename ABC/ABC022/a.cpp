#include <iostream>

using namespace std;

int main(void) {
    int N, S, T;
    cin >> N >> S >> T;
    int W, A[N - 1];
    cin >> W;
    for (int i = 0; i < N - 1; ++i) {
        cin >> A[i];
    }

    int cnt = 0;
    if (S <= W && W <= T) cnt++;
    for (int i = 0; i < N - 1; ++i) {
        W += A[i];
        if (S <= W && W <= T) cnt++;
    }

    cout << cnt << endl;
    return 0;
}