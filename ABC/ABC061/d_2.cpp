#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

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

const ll INF = 1LL << 50;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	int a[m], b[m];
	ll c[m];
	REP(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		c[i] = -c[i];
	}
	
	ll d[n];
	REP(i, n) d[i] = INF;
	
	d[0] = 0;
	
	REP(loop, n - 1) {
		REP(i, m) {
			if (d[a[i]] != INF && d[b[i]] > d[a[i]] + c[i]) {
				d[b[i]] = d[a[i]] + c[i];
			}
		}
	}
	
	ll ans = d[n - 1];
	
	
	bool negative[n];
	REP(i, n) negative[i] = false;
	
	REP(loop, n) {
		REP(i, m) {
			if (d[a[i]] == INF) continue;
			
			if (d[b[i]] > d[a[i]] + c[i]) {
				d[b[i]] = d[a[i]] + c[i];
				negative[b[i]] = true;
			}
			
			if (negative[a[i]]) {
				negative[b[i]] = true;
			}
		}
	}
	
	if (negative[n - 1]) cout << "inf" << endl;
	else cout << -ans << endl;
	
	return 0;
}