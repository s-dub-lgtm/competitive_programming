#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
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

int rev(int num) {
	int res = 0;
	while (num > 0) {
		res += num % 10;
		num /= 10;
		if (num > 0) {
			res *= 10;
		}
	}
	return res;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	ll sum = 0;
	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			int x = i, y = j;
			cout << "before" << endl;
			cout << x << " " << y << endl;
			
			if (x < y) {
				x = rev(x);
			} else {
				y = rev(y);
			}
			
			if (x < y) {
				y = y - x;
			} else {
				x = x - y;
			}
			if (x / 10 != 0 && y / 10 != 0 && rev(i) == rev(j)) sum++;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}