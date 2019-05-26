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
	
	int n, m;
	cin >> n >> m;
	int k[m];
	vector<vector<int>> s(m);
	rep(i, m) {
		cin >> k[i];
		rep(j, k[i]) {
			int s_in;
			cin >> s_in;
			s_in--;
			s[i].push_back(s_in);
		}
	}
	int p[m];
	rep(i, m) {
		cin >> p[i];
	}
	
	ll sum = 0;
	rep(i, 1 << n) {
//		cout << i << endl;
		int cnt[m];
		rep(j, m) {
			int ecnt = 0;
			for (int es: s[j]) {
//				cout << es << " ";
				if (i >> es & 1) {
					ecnt++;
				}
			}
//			cout << ecnt << endl;
			cnt[j] = ecnt;
		}
		bool ok = true;
		rep(j, m) {
			if (cnt[j] % 2 != p[j]) {
				ok = false;
			}
		}
		if (ok) sum++;
	}
	
	cout << sum << endl;
	
	return 0;
}