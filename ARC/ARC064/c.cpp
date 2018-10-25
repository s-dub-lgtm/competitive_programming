#include <iostream>

using namespace std;

#define MAX_N 100000

// 入力
int N;
long long x;
long long a[MAX_N + 1];

int main(void) {
    cin >> N >> x;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    long long new_a[MAX_N + 1];
    for (int i = 1; i <= N; ++i) {
        new_a[i] = a[i];
    }

    if (new_a[1] > x) new_a[1] = x;

    for (int i = 1; i <= N - 1; ++i) {
        if (new_a[i] + new_a[i + 1] > x) {
            new_a[i + 1] = x - new_a[i];
        }
    }

    long long operationNum = 0;
    for (int i = 1; i <= N; ++i) {
//        cout << a[i] << " " << new_a[i] << endl;
        operationNum += a[i] - new_a[i];
    }

    cout << operationNum << endl;
    return 0;
}