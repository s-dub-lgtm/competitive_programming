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
	
	int l;
	cin >> l;
	ll a[l];
	rep(i, l) cin >> a[i];
	
	int headnonzero = -1;
	rep(i, l) {
		if (a[i] != 0) {
			headnonzero = i;
			break;
		}
	}
	int tailnonzero = l;
	repr(i, l) {
		if (a[i] != 0) {
			tailnonzero = i;
			break;
		}
	}
//	cout << headnonzero << " " << tailnonzero << endl;
	
	if (headnonzero == -1 and tailnonzero == l) {
		cout << 0 << endl;
		return 0;
	}
	if (tailnonzero - headnonzero <= 1) {
		cout << 0 << endl;
		return 0;
	}
//	cout << "go3" << endl;
	
	if (a[headnonzero] % 2 == 0) {
		bool onlyheadeven = true;
		FORE(i, headnonzero + 1, tailnonzero) {
			if (a[i] % 2 == 0) {
				onlyheadeven = false;
				break;
			}
		}
		if (onlyheadeven) {
			cout << 0 << endl;
			return 0;
		}
	} else if (a[tailnonzero] % 2 == 0) {
		bool onlytaileven = true;
		FORE(i, headnonzero, tailnonzero - 1) {
			if (a[i] % 2 == 0) {
				onlytaileven = false;
				break;
			}
		}
		if (onlytaileven) {
			cout << 0 << endl;
			return 0;
		}
	}

//	cout << "go" << endl;
	
	ll zerocnt = 0;
	ll evencnt = 0;
	FORE(i, headnonzero, tailnonzero) {
		if (a[i] == 0) zerocnt++;
		else if (a[i] % 2 == 0) evencnt++;
	}
	
	if (evencnt == 0 and zerocnt == 0) {
		cout << 0 << endl;
		return 0;
	}
//	cout << "go2" << endl;
	if (a[headnonzero] % 2 == 0 or a[tailnonzero] % 2 == 0) evencnt--;
	
	cout << zerocnt + evencnt / 2 << endl;
	
	
	return 0;
}