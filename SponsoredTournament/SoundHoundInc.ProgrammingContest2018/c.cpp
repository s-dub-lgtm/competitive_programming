#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m, d;
	cin >> n >> m >> d;
	
	int cnt = 0;
	if (d == 0) {
		cnt = n;
	} else {
		FOR(i, 1, n + 1) {
			if (i + d <= n) cnt++;
			if (i - d >= 1) cnt++;
		}
	}
	
//	cout << cnt << endl;

//	cout << (double) ((cnt) * pow(n, (m - 1))) / pow(n, m) << endl;
//	cout << (double) (cnt) / n << endl;
//	if (d == 0) cnt = cnt / 2;
//	cout << ((long double) (m - 1) / (long double) n) * ((long double) cnt / (long double) n) << endl;
	printf("%.9f\n",((double) (m - 1) / (double) n) * ((double) cnt / (double) n));
	
	return 0;
}