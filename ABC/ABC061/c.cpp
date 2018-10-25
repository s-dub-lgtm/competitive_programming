#include <iostream>

using namespace std;

int main(void) {
    int N;
    long long K;
    cin >> N >> K;

    long long mem[100001];
    for (int i = 1; i <= 100000; ++i) {
        mem[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        mem[a] += b;
    }

    long long sum = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (K <= mem[i]) {
            cout << i << endl;
            break;
        }
        K -= mem[i];
    }

    return 0;
}