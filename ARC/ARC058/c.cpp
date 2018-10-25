#include <iostream>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    int D[K];
    for (int i = 0; i < K; ++i) {
        cin >> D[i];
    }

    int pay = N;
    while (1) {
        bool no_appear = true;
        int tmp = pay;
        while (tmp != 0) {
            int least = tmp % 10;
            for (int i = 0; i < K; ++i) {
                if (least == D[i]) {
                    no_appear = false;
                    break;
                }
            }
            tmp = tmp / 10;
        }
        if (no_appear) {
            break;
        }
        pay++;
    }

    cout << pay << endl;
    return 0;
}