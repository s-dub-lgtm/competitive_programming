#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int X[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    int Y[N];
    for (int i = 0; i < N; ++i) {
        Y[i] = X[i];
    }
    sort(X, X + N);

    double mid = ((double) (X[(N / 2) - 1] + X[N / 2])) / 2;
//    cout << mid << endl;
    for (int i = 0; i < N; ++i) {
        if (Y[i] <= mid) {
            cout << X[N / 2] << endl;
        } else {
            cout << X[(N / 2) - 1] << endl;
        }
    }
    return 0;
}