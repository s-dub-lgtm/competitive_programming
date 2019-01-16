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
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

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
	
	int n, m;
	cin >> n >> m;
	int x[m], y[m];
	rep(i, m) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}
	
	int num[n];
	rep(i, n) num[i] = 1;
	bool red[n];
	rep(i, n) {
		if (i == 0) red[i] = true;
		else red[i] = false;
	}
	
	rep(i, m) {
		if (num[x[i]] >= 2 and red[x[i]] == true) {
			red[y[i]] = true;
		}
		if (num[x[i]] == 1 and red[x[i]] == true) {
			red[x[i]] = false;
			red[y[i]] = true;
		}
		num[x[i]]--;
		num[y[i]]++;
//		rep(i, n) cout << num[i] << " " << red[i] << endl;
	}
	
	int cnt = 0;
	rep(i, n) {
		if (red[i]) cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}