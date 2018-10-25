#include <iostream>

using namespace std;

int main(void) {
    int N, M, X;
    cin >> N >> M >> X;
    int A[M];
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    int leftcost = 0, rightcost = 0;
    for (int i = X - 1; i >= 0; --i) {
        bool charge = false;
        for (int j = 0; j < M; ++j) {
            if (i == A[j]) {
                charge = true;
                break;
            }
        }
        if (charge) {
            leftcost++;
        }
    }
    for (int i = X + 1; i <= N; ++i) {
        bool charge = false;
        for (int j = 0; j < M; ++j) {
            if (i == A[j]) {
                charge = true;
                break;
            }
        }
        if (charge) {
            rightcost++;
        }
    }

    cout << min(leftcost, rightcost) << endl;
    return 0;
}