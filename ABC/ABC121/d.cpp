#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(ll i=0;i<(n);++i)
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
	
	ll a, b;
	cin >> a >> b;
	
	if (a == b) {
		cout << a << endl;
		return 0;
	}
	
	ll fb = 0;
	while (b > 0) {
//		cout << "   " << b << endl;
		if (b == 1) {
			fb += 1;
			break;
		}
		if (b == 2) {
			fb += 3;
			break;
		}
		if (b == 3) {
			break;
		}
		rep(i, 100) {
//			cout << i << endl;
			if (pow(2LL, i) == b) {
				fb += b;
				b = 0;
				break;
			} else if (b == pow(2LL, i + 1) - 1) {
				b = 0;
				break;
			} else if (pow(2LL, i) < b and b < pow(2LL, i + 1) - 1) {
//				cout << " " << pow(2LL, i) << endl;
//				cout << "      " << fmod(b - pow(2LL, i) - 1, 2LL) << endl;
				fb += fmod(b - pow(2LL, i) - 1, 2LL) * pow(2LL, i);
//				cout << fmod(b - pow(2LL, i) - 1, 2LL) * pow(2LL, i) << " " << fb << endl;
				b -= pow(2LL, i);
				break;
			}
		}
	}
//	cout << fb << endl;
//	cout << "break" << endl;
	
	if (a == 0) {
		cout << fb << endl;
		return 0;
	}
	
	ll fa = 0;
	a--;
	while (a > 0) {
//		cout << "   " << a << endl;
		if (a == 1) {
			fa += 1;
			break;
		}
		if (a == 2) {
			fa += 3;
			break;
		}
		if (a == 3) {
			break;
		}
		rep(i, 100) {
//			cout << i << endl;
			if (pow(2LL, i) == a) {
				fa += a;
				a = 0;
				break;
			} else if (a == pow(2LL, i + 1) - 1) {
				a = 0;
				break;
			} else if (pow(2LL, i) < a and a < pow(2LL, i + 1) - 1) {
//				cout << " " << pow(2LL, i) << endl;
//				cout << "      " << fmod(a - pow(2LL, i) - 1, 2LL) << endl;
				fa += fmod(a - pow(2LL, i) - 1, 2LL) * pow(2LL, i);
//				cout << fmod(a - pow(2LL, i) - 1, 2LL) * pow(2LL, i) << " " << fa << endl;
				a -= pow(2LL, i);
				break;
			}
		}
	}
//	cout << fa << endl;
	
	cout << (fb xor fa) << endl;
	
	return 0;
}