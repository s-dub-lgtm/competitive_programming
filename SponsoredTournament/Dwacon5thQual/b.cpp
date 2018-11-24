#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	ll a[n];
	rep(i, n) cin >> a[i];
	
	ll b[(n * (n + 1)) / 2];
	int cnt = 0;
	rep(i, n) {
		ll sum = 0;
		FOR(j, i, n) {
			sum += a[j];
			b[cnt] = sum;
			cnt++;
		}
	}

//	rep(i, (n * (n + 1)) / 2) cout << b[i] << " ";
//	cout << endl;
	
	sort(b, b + (n * (n + 1) / 2));
	reverse(b, b + (n * (n + 1) / 2));
	
	ll tmplog = 0;
	cnt = 1;
	rep(i, (n * (n + 1)) / 2) {
		ll nowlog = (ll) (log2(b[i]));
//		cout << nowlog << endl;
//		cout << cnt << endl;
		if (nowlog != tmplog) {
			cnt = 1;
			tmplog = nowlog;
			continue;
		} else {
			cnt++;
			if (cnt == k) {
				ll ans = b[i - k + 1];
//				cout << ans << endl;
				rep(j, k) {
					ans = ans & b[i + j];
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	
	ll ans = b[0];
//	cout << ans << endl;
	cnt = 0;
	rep(i, (n * (n + 1)) / 2) {
		if ((ans & b[i]) >= b[i]) {
			ans = ans & b[i];
			cnt++;
		}
		if (cnt == k) break;
	}
	
	cout << ans << endl;
	
	return 0;
}