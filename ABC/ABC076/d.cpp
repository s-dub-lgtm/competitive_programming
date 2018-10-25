#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int INF = 1LL << 30;
int MOD = 1e9 + 7;

int main(void) {
    int N;
    cin >> N;
    vector<int> L(N + 2), R(N + 2), V(N + 2);
    int T = 0;
    //l(s) - r(s)
    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        t *= 2;//
        L[i] = R[i - 1];
        R[i] = L[i] + t;
        T += t;
    }
    for (int i = 1; i <= N; i++)cin >> V[i], V[i] *= 2;
    L[N + 1] = R[N + 1] = T;
    vector<double> vel;
    for (int i = 0; i <= T; i++) {
        double v = INF;
        int t = i;
        for (int j = 0; j < N + 2; j++) {
            if (t <= L[j]) v = min(v, 1. * V[j] + L[j] - t);
            else if (t >= R[j]) v = min(v, 1. * V[j] + t - R[j]);
            else v = min(v, 1. * V[j]);
        }
        vel.push_back(v);
    }
    double sum = 0;
    for (int i = 0; i < T; i++) {
        sum += 0.25 * (vel[i] + vel[i + 1]);
    }
    printf("%.9lf\n", sum / 2);

    return 0;
}