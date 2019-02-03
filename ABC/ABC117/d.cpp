#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define repr(i, n) for(int i=(n-1);i>=0;--i)
#define repre(i, n) for(int i=(n);i>=0;--i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, k;
	cin >> n >> k;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll c[n];
	rep(i, n) c[i] = a[i];
	
	if (k == 0) {
		ll sum = 0;
		rep(i, n) sum += c[i];
		cout << sum << endl;
		return 0;
	}
	
	ll onecnt[60] = {};
	rep(i, n) {
		ll index = 0;
		while (a[i] > 0) {
			if (a[i] % 2 == 1) onecnt[index]++;
			a[i] /= 2;
			index++;
		}
	}
//	rep(i, 50) cout << onecnt[i] << " ";
//	cout << endl;
	
	ll digit = 0;
	ll tmp = k;
	while (k > 0) {
		digit++;
		k /= 2;
	}
	k = tmp;
//	cout << digit << endl;
	
	ll best[digit];
	rep(i, digit) {
		if (onecnt[i] >= (n + 1) / 2) best[i] = 0;
		else best[i] = 1;
	}
//	rep(i, digit) cout << best[i] << " ";
//	cout << endl;
	
	ll b = 0;
	rep(i, digit) b += best[i] * pow(2, i);
//	cout << b << endl;
	
	if (b > k) {
		ll index = digit - 1;
		while (b > k) {
			if (k & (1 << index) == 0 and b & (1 << index) == 1) {
				b -= pow(2, index);
			} else if (k & (1 << index) == 1 and b & (1 << index) == 0) {
				break;
			}
			index--;
		}
//		cout << b << endl;
	}
//	if (b > k) b = k;
	
	ll sum = 0;
	rep(i, n) sum += b xor c[i];
	
	cout << sum << endl;
	
	return 0;
}