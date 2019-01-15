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
	
	int n;
	cin >> n;
	int b[n];
	rep(i, n) {
		int a;
		cin >> a;
		b[i] = a - (i + 1);
	}
	
	sort(b, b + n);
	
	if (n % 2 == 1) {
		int mid = b[n / 2];
		ll sum = 0;
		rep(i, n) sum += abs(b[i] - mid);
		cout << sum << endl;
	} else {
		int mid1 = b[n / 2 - 1];
		ll sum1 = 0;
		rep(i, n) sum1 += abs(b[i] - mid1);
		
		int mid2 = b[n / 2];
		ll sum2 = 0;
		rep(i, n) sum2 += abs(b[i] - mid2);
		
		cout << min(sum1, sum2) << endl;
	}
	
	return 0;
}