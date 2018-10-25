#include <iostream>

using namespace std;

#define MAX_N 100000

int N, A, B;
int h[MAX_N];

bool enough(int t) {
    long long cnt = 0;
    for (int i = 0; i < N; ++i) {
        long long top = (long long) h[i] - (long long) B * t;
        if (top <= 0) continue;
        cnt += top / (A - B);
        if (top % (A - B)) cnt++;
    }
    return cnt <= t;
}

int main(void) {
    cin >> N >> A >> B;
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int lb = 0, ub = 1000000001;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (enough(mid)) ub = mid;
        else lb = mid;
    }

    cout << ub << endl;
    return 0;
}