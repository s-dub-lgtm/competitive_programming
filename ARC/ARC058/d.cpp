#include <iostream>

using namespace std;

using ll = long long;

ll mod_pow(ll x, ll p, ll MOD) {
    ll a = 1;
    while (p) {
        if (p % 2) a = a * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return a;
}

// mod_inverse
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

const int MOD = 1e9 + 7;

const int MAX = 333333;
ll fact[MAX], rfact[MAX];

ll nCr(int n, int r) {
    return fact[n] * rfact[r] % MOD * rfact[n - r] % MOD;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rfact[i] = mod_inverse(fact[i], MOD);
    }
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    ll ans = 0;
    for (int i = B + 1; i <= W; i++) {
        int h = H - A - 1, w = i - 1;
        ll tmp = nCr(h + w, h);
        h = A - 1, w = W - i;
        tmp *= nCr(h + w, w);
        ans += tmp % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}