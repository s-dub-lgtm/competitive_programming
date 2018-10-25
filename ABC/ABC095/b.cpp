#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, X;
    cin >> N >> X;
    int m[N];
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }

    sort(m, m + N);

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        X -= m[i];
        cnt++;
    }

    cnt += X / m[0];

    cout << cnt << endl;
    return 0;
}