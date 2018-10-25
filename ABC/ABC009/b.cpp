#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A, A + N);

    int ans;
    for (int i = N - 2; i >= 0; --i) {
        if (A[i] != A[N - 1]) {
            ans = A[i];
            break;
        }
    }

    cout << ans << endl;
    return 0;
}