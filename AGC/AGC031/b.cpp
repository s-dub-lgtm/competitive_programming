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
const ll MOD = (ll) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int c[n];
	rep(i, n) cin >> c[i];
	
	ll cnt[n + 10];
	rep(i, n + 10) cnt[i] = 0;
	
	int before = 0;
	rep(i, n) {
		if (c[i] != before) cnt[c[i]]++;
		before = c[i];
	}
//	rep(i, n + 10) cout << cnt[i] << endl;
	
	ll sum = 1;
	rep(i, n + 10) {
		if (cnt[i] == 2) {
			sum++;
		} else if (cnt[i] >= 3) {
			sum += (cnt[i] - 1) * (cnt[i] - 1) - 1;
		}
		sum %= MOD;
	}
	
	ll paircnt = 0;
	bool searchpair = false;
	int pairnum;
	int pairindex;
	rep(i, n) {
		if (!searchpair) {
			pairnum = c[i];
			pairindex = i;
			searchpair = true;
		} else {
			if (c[i] == pairnum) {
				if (i - pairindex != 1) {
					paircnt++;
					searchpair = false;
				}
			}
		}
	}
//	cout << paircnt << endl;
	
	if (paircnt >= 2) {
		sum += paircnt - 1;
	}
	sum %= MOD;
	
	cout << sum << endl;
	
	return 0;
}